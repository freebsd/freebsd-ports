#
# $FreeBSD$
#
# bsd.hackage.mk -- List of Haskell Cabal ports.
#
# Created by: Gabor Pali <pgj@FreeBSD.org>,
# Based on works of Giuseppe Pilichi and Ashish Shukla.
#
# Maintained by: haskell@FreeBSD.org
#

# KEEP THE LIST ALPHABETICALLY SORTED!

Agda_port=			math/hs-Agda		# executable
Agda-executable_port=		math/hs-Agda-executable	# executable
alex_port=			devel/hs-alex		# executable
ALUT_port=			audio/hs-ALUT
ansi-terminal_port=		devel/hs-ansi-terminal
ansi-wl-pprint_port=		devel/hs-ansi-wl-pprint
arrows_port=			devel/hs-arrows
binary_port=			devel/hs-binary
bio_port=			science/hs-bio
brainfuck_port=			lang/hs-brainfuck	# executable
bytestring-csv_port=		textproc/hs-bytestring-csv
c2hs_port=			devel/hs-c2hs		# exectuable
category-extras_port=		math/hs-category-extras
cgi_port=			www/hs-cgi
checkers_port=			devel/hs-checkers
citeproc-hs_port=		textproc/hs-citeproc-hs
convertible_port=		devel/hs-convertible
cpphs_port=			devel/hs-cpphs		# executable
criterion_port=			benchmarks/hs-criterion
curl_port=			ftp/hs-curl
darcs_port=			devel/darcs		# executable
dataenc_port=			converters/hs-dataenc
datetime_port=			devel/hs-datetime
DeepArrow_port=			devel/hs-DeepArrow
deepseq_port=			devel/hs-deepseq
Diff_port=			textproc/hs-Diff
digest_port=			security/hs-digest
dlist_port=			devel/hs-dlist
erf_port=			math/hs-erf
fastcgi_port=			www/hs-fastcgi		# lib_depends
feed_port=			textproc/hs-feed
fgl_port=			devel/hs-fgl
FileManip_port=			devel/hs-FileManip
ghc-mtl_port=			devel/hs-ghc-mtl
ghc-paths_port=			devel/hs-ghc-paths
GLURaw_port=			x11-toolkits/hs-GLURaw
GLUT_port=			x11-toolkits/hs-GLUT
haddock_port=			devel/hs-haddock	# executable
happy_port=			devel/hs-happy		# executable
hashed-storage_port=		devel/hs-hashed-storage
haskeline_port=			devel/hs-haskeline
haskell-src-exts_port=		devel/hs-haskell-src-exts
HaXml_port=			textproc/hs-HaXml	# executable
HGL_port=			graphics/hs-HGL
highlighting-kate_port=		textproc/hs-highlighting-kate
hint_port=			devel/hs-hint
hoogle_port=			devel/hs-hoogle		# executable
hostname_port=			net/hs-hostname
hs-bibutils_port=		textproc/hs-hs-bibutils
hscolour_port=			print/hs-hscolour	# executable
hslogger_port=			devel/hs-hslogger
HTTP_port=			www/hs-HTTP
http-server_port=		www/hs-http-server
hxt_port=			textproc/hs-hxt
json_port=			converters/hs-json
language-c_port=		devel/hs-language-c
lazysmallcheck_port=		devel/hs-lazysmallcheck
libmpd_port=			audio/hs-libmpd
libxml_port=			textproc/hs-libxml
MemoTrie_port=			devel/hs-MemoTrie
mime_port=			mail/hs-mime
MissingH_port=			devel/hs-MissingH
mmap_port=			devel/hs-mmap
MonadCatchIO-mtl_port=		devel/hs-MonadCatchIO-mtl
mueval_port=			devel/hs-mueval		# executable
mwc-random_port=		math/hs-mwc-random
ObjectName_port=		devel/hs-ObjectName
oeis_port=			www/hs-oeis
OpenAL_port=			audio/hs-OpenAL
OpenGL_port=			x11-toolkits/hs-OpenGL
OpenGLRaw_port=			x11-toolkits/hs-OpenGLRaw
pandoc_port=			textproc/hs-pandoc	# executable
pcap_port=			net/hs-pcap
pcre-light_port=		devel/hs-pcre-light	# lib_depends
polyparse_port=			textproc/hs-polyparse
porte_port=			ports-mgmt/hs-porte	# executable
probability_port=		math/hs-probability
QuickCheck_port=		devel/hs-QuickCheck
reactive_port=			devel/hs-reactive
readline_port=			devel/hs-readline
safe_port=			devel/hs-safe
scgi_port=			www/hs-scgi
SHA_port=			security/hs-SHA
show_port=			devel/hs-show
smallcheck_port=		devel/hs-smallcheck
split_port=			devel/hs-split
StateVar_port=			devel/hs-StateVar
statistics_port=		math/hs-statistics
Stream_port=			devel/hs-Stream
stringsearch_port=		textproc/hs-stringsearch
tagsoup_port=			textproc/hs-tagsoup	# executable
Tensor_port=			devel/hs-Tensor
terminfo_port=			devel/hs-terminfo
test-framework_port=		devel/hs-test-framework
test-framework-hunit_port=	devel/hs-test-framework-hunit
test-framework-quickcheck2_port=	devel/hs-test-framework-quickcheck2
testpack_port=			devel/hs-testpack
texmath_port=			textproc/hs-texmath	# executable
transformers_port=		devel/hs-transformers
TypeCompose_port=		devel/hs-TypeCompose
unamb_port=			devel/hs-unamb
uniplate_port=			devel/hs-uniplate
unix-compat_port=		devel/hs-unix-compat
unlambda_port=			lang/hs-unlambda	# executable
url_port=			www/hs-url
utf8-string_port=		devel/hs-utf8-string
utility-ht_port=		devel/hs-utility-ht
uuagc_port=			devel/hs-uuagc		# executable
uulib_port=			devel/hs-uulib
uvector_port=			devel/hs-uvector
uvector-algorithms_port=	devel/hs-uvector-algorithms
vector-space_port=		math/hs-vector-space
X11_port=			x11/hs-X11		# lib_depends
X11-xft_port=			x11/hs-X11-xft
xml_port=			textproc/hs-xml
xmobar_port=			x11/hs-xmobar		# executable
xmonad_port=			x11-wm/hs-xmonad	# executable
xmonad-contrib_port=		x11-wm/hs-xmonad-contrib
zip-archive_port=		archivers/hs-zip-archive
zlib_port=			archivers/hs-zlib
