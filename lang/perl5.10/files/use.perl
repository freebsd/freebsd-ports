#!/bin/sh

# $FreeBSD$

this=`echo -n $0 | /usr/bin/sed -e 's!^.*/!!'`
PERL_VERSION="%%PERL_VERSION%%"
MAKE_CONF=%%MAKE_CONF%%
banner=`date +"%F %T"`
banner="# added by use.perl $banner"
if [ -z "${OSVERSION}" ]; then
	if [ -f /sbin/sysctl -a -x /sbin/sysctl ] ; then
    		osreldate=`/sbin/sysctl -n kern.osreldate`
	else
    		osreldate=`/usr/sbin/sysctl -n kern.osreldate`
	fi
else
    	osreldate=${OSVERSION}
fi

if [ "x$this" = "xuse.perl" ]; then
	PKG_PREFIX="%%PREFIX%%"
	if [ "$1" = "port" ] ; then
		need_remove_links=yes
		need_create_links=yes
		need_cleanup_make_conf=yes
		need_cleanup_manpath=yes
		need_spam_make_conf=yes
		need_spam_manpath=yes
	elif [ "$1" = "system" ] ; then
		need_remove_links=yes
		if [ $osreldate -lt 500036 ] ; then
			need_base_system_perl=yes
		fi
		need_cleanup_make_conf=yes
		need_cleanup_manpath=yes
	else
		echo "Usage:
	${0##*/} port       -> /usr/bin/perl is the perl5 port
	${0##*/} system     -> /usr/bin/perl is the system perl"
		exit 2;
	fi
else
	if [ "$2" = "POST-INSTALL" ] ; then
		need_remove_links=yes
		if [ $osreldate -ge 500036 ] ; then
			need_create_links=yes
			need_cleanup_make_conf=yes
			need_cleanup_manpath=yes
			need_spam_make_conf=yes
			need_spam_manpath=yes
		fi
		need_post_install=yes
	elif [ "$2" = "POST-DEINSTALL" ] ; then
		need_remove_links=yes
		if [ $osreldate -lt 500036 ] ; then
			need_base_system_perl=yes
		fi
		need_cleanup_make_conf=yes
		need_cleanup_manpath=yes
	else
		exit 0;
	fi
fi

link_list="
	a2p
	c2ph
	find2perl
	h2ph
	h2xs
	perlbug
	perlcc
	perldoc
	pl2pm
	pod2html
	pod2latex
	pod2man
	pod2text
	s2p
	splain
	suidperl"
if [ $osreldate -ge 500036 ] ; then
	link_list=""
fi
special_link_list="
	perl
	perl5"

do_remove_links()
{
	echo "Removing stale symlinks from /usr/bin..."
	for binary in $link_list $special_link_list
	do
		if [ -L "/usr/bin/$binary" ] ; then
			echo "    Removing /usr/bin/$binary"
			/bin/rm -f "/usr/bin/$binary"
		else
			echo "    Skipping /usr/bin/$binary"
		fi
	done
	bins=`/bin/ls /usr/bin/*perl*5.* ${PKG_PREFIX}/bin/*perl*5.* 2>/dev/null`
	for binary in $bins
	do
		if [ -L "$binary" ] ; then
			echo "    Removing $binary installed by an older perl port"
			/bin/rm -f "$binary"
		fi
	done
	echo "Done."
}

do_create_links()
{
	echo "Creating various symlinks in /usr/bin..."
	for binary in $link_list
	do
		if [ -f "/usr/bin/$binary" ] ; then
			echo "    Backing up /usr/bin/$binary as /usr/bin/$binary.freebsd"
			/bin/mv -f "/usr/bin/$binary" "/usr/bin/$binary.freebsd"
		fi
		if [ -e "/usr/bin/$binary" ] ; then
			echo "    *** /usr/bin/$binary is still there, which should not happen"
		elif [ -e "$PKG_PREFIX/bin/$binary" ] ; then
			echo "    Symlinking $PKG_PREFIX/bin/$binary to /usr/bin/$binary"
			/bin/ln -sf "$PKG_PREFIX/bin/$binary" "/usr/bin/$binary"
		else
			echo "    *** $PKG_PREFIX/bin/$binary is not there, a symlink won't do any good"
		fi
	done
	for binary in $special_link_list
	do
		if [ -f "/usr/bin/$binary" ] ; then
			echo "    Backing up /usr/bin/$binary as /usr/bin/$binary.freebsd"
			/bin/mv -f "/usr/bin/$binary" "/usr/bin/$binary.freebsd"
		fi
		bin=`echo $binary | /usr/bin/sed -e 's!perl5!perl!'`
		if [ -e "/usr/bin/$binary" ] ; then
			echo "    *** /usr/bin/$binary is still there, which should not happen"
		elif [ -e "$PKG_PREFIX/bin/${bin}%%PERL_VERSION%%" ] ; then
			echo "    Symlinking $PKG_PREFIX/bin/${bin}%%PERL_VERSION%% to /usr/bin/$binary"
			/bin/ln -sf "$PKG_PREFIX/bin/${bin}%%PERL_VERSION%%" "/usr/bin/$binary"
		else
			echo "    *** $PKG_PREFIX/bin/${bin}%%PERL_VERSION%% is not there, a symlink won't do any good"
		fi
	done
	echo "Done."
}

do_base_system_perl()
{
	echo "Restoring base system perl binaries..."
	for binary in $link_list
	do
		if [ -e "/usr/bin/$binary" ] ; then
			echo "    *** /usr/bin/$binary is there, which should not happen"
		else
			if [ -f "/usr/bin/$binary.freebsd" ] ; then
				echo "    Moving /usr/bin/$binary.freebsd to /usr/bin/$binary"
				/bin/mv -f "/usr/bin/$binary.freebsd" "/usr/bin/$binary"
			else
				echo "    *** /usr/bin/$binary.freebsd is NOT there, nothing to restore"
			fi
		fi
	done
	for binary in $special_link_list
	do
		if [ -e "/usr/bin/$binary" ] ; then
			echo "    *** /usr/bin/$binary is there, which should not happen"
		else
			bin=`echo $binary | /usr/bin/sed -e 's!perl5!perl!'`
			bin=`echo $bin | /usr/bin/sed -e 's!suidperl!sperl!'`
			bins=`/bin/ls /usr/bin/${bin}5.* 2>/dev/null | /usr/bin/sort`
			bin=""
			for b in $bins
			do
				if [ -f $b -a ! -L $b ] ; then
					bin=$b
				fi
			done
			if [ -z $bin ] ; then
				echo "    *** cannot find what /usr/bin/$binary shall be restored FROM"
			elif [ -f $bin ] ; then
				echo "    Hardlinking $bin to /usr/bin/$binary"
				ln -f "$bin" "/usr/bin/$binary"
			else
				echo "    *** $bin is NOT there, nothing to restore"
			fi
			if [ -f "/usr/bin/$binary.freebsd" ] ; then
				echo "    Removing backup copy /usr/bin/$binary.freebsd"
				rm -f "/usr/bin/$binary.freebsd"
			fi
		fi
	done
	echo "Done."
}

do_post_install()
{
	INCLUDEDIR=/usr/include
	install -d ${PKG_PREFIX}/lib/perl5/site_perl/%%PERL_VERSION%%/%%PERL_ARCH%%/auto
	install -d ${PKG_PREFIX}/lib/perl5/site_perl/%%PERL_VERSION%%/auto
	install -d ${PKG_PREFIX}/lib/perl5/%%PERL_VERSION%%/man/man3
	cd ${INCLUDEDIR} && ${PKG_PREFIX}/bin/h2ph *.h machine/*.h sys/*.h >/dev/null
}

do_cleanup_make_conf()
{
	echo -n "Cleaning up ${MAKE_CONF}..."
	if [ -f ${MAKE_CONF} ] ; then
		/usr/bin/awk 's=0;
			/^#.*use.perl/ { s=1; mode=1 }
			/^#/ { s=1; if (mode != 1) { mode=0 } }
			/.*PERL.*=/ { s=1; if (mode == 1) { mode=2 } }
			/^$/ { s=1; if (mode != 2) { mode = 0 } }
			{ if (s != 1) { mode = 0 } if (mode == 0) print }' ${MAKE_CONF} >${MAKE_CONF}.new
		/bin/mv ${MAKE_CONF} ${MAKE_CONF}.bak
		/bin/mv ${MAKE_CONF}.new ${MAKE_CONF}
	fi
	echo " Done."
}

do_cleanup_manpath()
{
	echo -n "Cleaning up /etc/manpath.config..."
	if [ -f /etc/manpath.config ] ; then
		/usr/bin/awk 's=0;
			/^#.*use.perl/ { s=1; mode=1 }
			/^#/ { s=1; if (mode != 1) { mode=0 } }
			/^OPTIONAL_MANPATH.*perl5/ { s=1; if (mode == 1) { mode=2 } }
			/^$/ { s=1; if (mode != 2) { mode = 0 } }
			{ if (s != 1) { mode = 0 } if (mode == 0) print }' /etc/manpath.config >/etc/manpath.config.new
		/bin/mv /etc/manpath.config /etc/manpath.config.bak
		/bin/mv /etc/manpath.config.new /etc/manpath.config
	fi
	echo " Done."
}

do_spam_make_conf()
{
	echo -n "Spamming ${MAKE_CONF}..."
	echo "$banner" >>${MAKE_CONF}
	echo "PERL_VER=%%PERL_VER%%" >>${MAKE_CONF}
	echo "PERL_VERSION=%%PERL_VERSION%%" >>${MAKE_CONF}
	if [ $osreldate -lt 500036 ] ; then
		echo "NOPERL=yes" >>${MAKE_CONF}
	fi
	echo " Done."
}

do_spam_manpath()
{
	echo -n "Spamming /etc/manpath.config..."
	echo "$banner" >>/etc/manpath.config
	echo "OPTIONAL_MANPATH	${PKG_PREFIX}/lib/perl5/%%PERL_VERSION%%/man" >>/etc/manpath.config
	echo "OPTIONAL_MANPATH	${PKG_PREFIX}/lib/perl5/%%PERL_VERSION%%/perl/man" >>/etc/manpath.config
	echo " Done."
}

[ $need_remove_links ] && do_remove_links
[ $need_create_links ] && do_create_links
[ $need_base_system_perl ] && do_base_system_perl
[ $need_post_install ] && do_post_install
[ $need_cleanup_make_conf ] && do_cleanup_make_conf
[ $need_spam_make_conf ] && do_spam_make_conf
[ $need_cleanup_manpath ] && do_cleanup_manpath
[ $need_spam_manpath ] && do_spam_manpath

exit 0
