require 'rbconfig'
require 'find'
require 'ftools'
require 'getoptlong'

Dir.chdir ".." if Dir.pwd =~ /bin.?$/

class Prefixizer
	attr_reader :orig_prefix, :my_prefix

	def initialize( orig_prefix = "/usr/local", my_prefix = nil )
		self.orig_prefix = orig_prefix
		self.my_prefix = my_prefix
	end
	
	def orig_prefix=( orig_prefix = "/usr/local" )
		@orig_prefix = orig_prefix
	end
	
	def my_prefix=( my_prefix = nil )
		@my_prefix = my_prefix
	end
	
	def prefixize( str )
		my_prefix ?
			str.gsub( Regexp::compile( "^#{Regexp::escape(orig_prefix)}" ), my_prefix ) :
			str
	end
end

include Config

prefixizer = Prefixizer.new( CONFIG["prefix"] )
no_harm = false

opts = GetoptLong.new( 
	[ "--no-harm", "-n", GetoptLong::OPTIONAL_ARGUMENT],
	[ "--prefix", "-p", GetoptLong::OPTIONAL_ARGUMENT]
)

opts.each { |opt, arg|
	case opt
	when "--no-harm"	
		no_harm = true
	when "--prefix"
		prefixizer.my_prefix = arg
	end
}

FREERIDE = "freeride"
$version = CONFIG["MAJOR"]+"."+CONFIG["MINOR"]
$libdir = prefixizer.prefixize( CONFIG["rubylibdir"] )
$archdir = prefixizer.prefixize( CONFIG["archdir"] )
$site_libdir = prefixizer.prefixize( CONFIG["sitelibdir"] )

$libdir = ["config", "plugins", "redist"]
$libdir_excl = [ /CVS[^\/]*$/, /i[36]86-/, /^rrb\//, /\.so\s*$/, /ripper/ ]
$libdir_subst = [ [/i686-linux/, CONFIG["arch"] ] ]

class Array
  def contains?
	each { |e| return true if yield( e ) }
	return false
  end

  def include_like?( pattern )
    return include?( pattern ) unless pattern.kind_of?( Regexp )
    return contains? { |v| ( v.kind_of?( String ) and (v =~ pattern) ) }
  end
end

class File
  def File.libdirPath( f )
    ofn = File.join($site_libdir, FREERIDE, f)
    $libdir_subst.each { |p, s| ofn.gsub!( p, s ) }
    ofn
  end
end

class String
	attr_accessor :localDir

	def rmLocal
		localDir = "/usr/local/" if localDir.nil?
		gsub( Regexp.new( "^#{Regexp.escape(localDir)}" ), "" )
    end
end

def dirmake( dir, noharm = false )
  for f in dir.sort.reverse
    next if f == "."
    next if f == "CVS"
    odn = File.libdirPath( f ).gsub(/\/\.$/, "" )
    if noharm then
      $stdout << "@dirrm #{odn.rmLocal}\n"
    else
      File::makedirs( odn )
    end
  end
end

def filecopy( path, noharm = false )
  for f in path
    ofn = File.libdirPath( f )
    if noharm then
      $stdout << "#{ofn.rmLocal}\n"
    else
      File::install( f, ofn, 0644, true)
    end
  end
end

def install_rb(noharm = false, srcdir = nil)
  libdir = $libdir
  libdir_excl = $libdir_excl
  libdir.collect! { |ld|
    File.join(srcdir, ld)
  } if srcdir
  path = ["freeride.rb"]
  dir = [ "" ]
  libdir.each { |ld|
    Find.find(ld) do |f|
      next unless FileTest.file?(f)
      next if (f = f[ld.length+1..-1]) == nil
      next if libdir_excl.contains? { |p| f =~ p }
      path.push File.join( ld, f )
      dir |= [File.join( ld, File.dirname(f) )]
      end
    }
  if noharm then
	filecopy( path, noharm )
	dirmake( dir, noharm )
  else
  	dirmake( dir, noharm )
	filecopy( path, noharm )
  end
  $stdout.flush
end

$stderr << "No-harm install\n" if no_harm
$stderr.flush
install_rb( no_harm )

