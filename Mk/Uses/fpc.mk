#
# $FreeBSD$
#
# Support for FPC-based ports. This automatically will install free pascal 
# compiler and units.
#
# Feature:      fpc
# Usage:        USES=fpc
# Valid ARGS:   (none), run, base, all
#
# run			- Free pascal units will be registered also as run dependencies.
#
# base			- This automatically will install all base units of fpc 
#			  (gdbint graph ibase libasync hash httpd mysql netdb odbc 
#			  oracle pasjpeg paszlib pthreads postgres regexpr and sqlite).
#
# all			- This automatically will install all free pascal units.
#
# if you need install additional fpc units, they can be listed there (USE_FPC=gtk2 x11 opengl).
#
# Example:
#	
#	USES+=	fpc:run
#	USE_FPC=gtk2
#

.if !defined(_INCLUDE_USES_FPC_MK)

FPC_Include_MAINTAINER= acm@FreeBSD.org

_INCLUDE_USES_FPC_MK=   yes

.if defined(DEFAULT_FPC_VER)
WARNING+=	"DEFAULT_FPC_VER is defined, consider using DEFAULT_VERSIONS=fpc=${DEFAULT_FPC_VER} instead"
.endif

.if ${fpc_ARGS:Nrun:Nbase:Nall}
IGNORE=		Unknown argument for USES=fpc: ${fpc_ARGS:Nrun:Nbase:Nall}
.endif

DEFAULT_FPC_VER=	${FPC_DEFAULT}
# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
FPC_VER=		${DEFAULT_FPC_VER}
FPC_ARCH=		${ARCH:S/amd64/x86_64/}

.if exists(${LOCALBASE}/bin/fpc)
FPC_CURRENT_VER!=	${LOCALBASE}/bin/fpc -iV
.	if ${FPC_CURRENT_VER} != ${FPC_VER}
IGNORE=	incompatible fpc ${FPC_CURRENT_VER} compiler, please install ${FPC_VER} version
.	endif
.endif

.if ${ARCH} == "i386"
PPNAME=			ppc386
.elif ${ARCH} == "amd64"
PPNAME=			ppcx64
.else
PPNAME=			ppc_not_yet_ported
ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	not yet ported to anything other than i386 and amd64
.endif

BUILD_DEPENDS+=		${LOCALBASE}/bin/as:devel/binutils \
			${PPNAME}:lang/fpc

BUILDNAME=		${FPC_ARCH}-${OPSYS:tl}
UNITSDIR=		${LOCALBASE}/lib/fpc/${FPC_VER}/units/${BUILDNAME}
MKINSTDIR=		${LOCALBASE}/lib/fpc/${FPC_VER}/fpmkinst/${BUILDNAME}

_FPC_ALL_UNITS=	a52 aspell bfd bzip2 cairo chm dblib dbus dts fastcgi \
		fcl-async fcl-base fcl-db fcl-extra fcl-fpcunit fcl-image \
		fcl-js fcl-json fcl-net fcl-passrc fcl-pdf fcl-registry \
		fcl-report fcl-res fcl-sdo fcl-sound fcl-stl fcl-web fcl-xml \
		fftw fpindexer fppkg fv gdbint gdbm gnutls gmp googleapi \
		graph gtk2 hermes httpd22 httpd24 ibase iconvenc imagemagick \
		ldap libcups libcurl libenet libfontconfig libgd libmagic \
		libmicrohttpd libpng libvlc libxml2 lua mad modplug \
		mysql ncurses newt numlib odata odbc oggvorbis openal opengl openssl \
		oracle pasjpeg pastojs pcap postgres proj4 pthreads pxlib \
		regexpr rexx rsvg rtl-console rtl-extra rtl-generics rtl-objpas \
		rtl-unicode sdl sqlite svgalib symbolic syslog unzip users utmp \
		uuid vcl-compat webidl x11 xforms zlib

.if ${fpc_ARGS:Mbase}
USE_FPC=	gdbint graph httpd22 httpd24 ibase mysql odbc oracle pasjpeg \
		postgres pthreads regexpr sqlite
.endif

.if ${fpc_ARGS:Mall}
USE_FPC=	${_FPC_ALL_UNITS}
.endif

.if defined(USE_FPC) && ${USE_FPC:tl} != "yes"
.	for UNITS in ${USE_FPC}
.		if ${_FPC_ALL_UNITS:M${UNITS}}==""
IGNORE= cannot install: unknown FPC unit ${UNITS}
.		endif
.	endfor
.endif

# Base units
gdbint_UNIT=	devel/fpc-gdbint
graph_UNIT=	graphics/fpc-graph
httpd22_UNIT=	www/fpc-httpd22
httpd24_UNIT=	www/fpc-httpd24
ibase_UNIT=	databases/fpc-ibase
mysql_UNIT=	databases/fpc-mysql
odbc_UNIT=	databases/fpc-odbc
oracle_UNIT=	databases/fpc-oracle
pasjpeg_UNIT=	graphics/fpc-pasjpeg
postgres_UNIT=	databases/fpc-postgres
pthreads_UNIT=	devel/fpc-pthreads
regexpr_UNIT=	devel/fpc-regexpr
sqlite_UNIT=	databases/fpc-sqlite

# Extra units
a52_UNIT=	audio/fpc-a52
aspell_UNIT=	textproc/fpc-aspell
bfd_UNIT=	devel/fpc-bfd
bzip2_UNIT=	archivers/fpc-bzip2
cairo_UNIT=	graphics/fpc-cairo
chm_UNIT=	misc/fpc-chm
dblib_UNIT=	databases/fpc-dblib
dbus_UNIT=	devel/fpc-dbus
dts_UNIT=	multimedia/fpc-dts
fastcgi_UNIT=	www/fpc-fastcgi
fcl_async_UNIT=	devel/fpc-fcl-async
fcl_base_UNIT=	devel/fpc-fcl-base
fcl_db_UNIT=	devel/fpc-fcl-db
fcl_extra_UNIT=	devel/fpc-fcl-extra
fcl_fpcunit_UNIT=	devel/fpc-fcl-fpcunit
fcl_image_UNIT=	devel/fpc-fcl-image
fcl_js_UNIT=	devel/fpc-fcl-js
fcl_json_UNIT=	devel/fpc-fcl-json
fcl_net_UNIT=	devel/fpc-fcl-net
fcl_passrc_UNIT=	devel/fpc-fcl-passrc
fcl_pdf_UNIT=	devel/fpc-fcl-pdf
fcl_registry_UNIT=	devel/fpc-fcl-registry
fcl_report_UNIT=	devel/fpc-fcl-report
fcl_res_UNIT=	devel/fpc-fcl-res
fcl_sdo_UNIT=	devel/fpc-fcl-sdo
fcl_sound_UNIT=	devel/fpc-fcl-sound
fcl_stl_UNIT=	devel/fpc-fcl-stl
fcl_web_UNIT=	devel/fpc-fcl-web
fcl_xml_UNIT=	devel/fpc-fcl-xml
fftw_UNIT=	math/fpc-fftw
fpindexer_UNIT=	databases/fpc-fpindexer
fppkg_UNIT=	devel/fpc-fppkg
fpvectorial_UNIT=	graphics/fpc-fpvectorial
fv_UNIT=	devel/fpc-fv
hermes_UNIT=	graphics/fpc-hermes
gdbm_UNIT=	databases/fpc-gdbm
gnutls_UNIT=	security/fpc-gnutls
gmp_UNIT=	math/fpc-gmp
googleapi_UNIT=	www/fpc-googleapi
gtk2_UNIT=	x11-toolkits/fpc-gtk2
iconvenc_UNIT=	converters/fpc-iconvenc
imagemagick_UNIT=	graphics/fpc-imagemagick
ldap_UNIT=	net/fpc-ldap
libcurl_UNIT=	ftp/fpc-libcurl
libcups_UNIT=	print/fpc-libcups
libenet_UNIT=	net/fpc-libenet
libfontconfig_UNIT=	x11-fonts/fpc-libfontconfig
libgd_UNIT=	graphics/fpc-libgd
libmagic_UNIT=	devel/fpc-libmagic
libmicrohttpd_UNIT=	www/fpc-libmicrohttpd
libpng_UNIT=	graphics/fpc-libpng
libvlc_UNIT=	multimedia/fpc-libvlc
libxml2_UNIT=	textproc/fpc-libxml2
lua_UNIT=	lang/fpc-lua
mad_UNIT=	audio/fpc-mad
modplug_UNIT=	audio/fpc-modplug
newt_UNIT=	devel/fpc-newt
ncurses_UNIT=	graphics/fpc-ncurses
numlib_UNIT=	math/fpc-numlib
odata_UNIT=	devel/fpc-odata
oggvorbis_UNIT=	audio/fpc-oggvorbis
openal_UNIT=	audio/fpc-openal
opengl_UNIT=	graphics/fpc-opengl
openssl_UNIT=	security/fpc-openssl
pastojs_UNIT=	lang/fpc-pastojs
pcap_UNIT=	net/fpc-pcap
proj4_UNIT=	graphics/fpc-proj4
pxlib_UNIT=	databases/fpc-pxlib
rexx_UNIT=	lang/fpc-rexx
rsvg_UNIT=	graphics/fpc-rsvg
rtl_console_UNIT=	lang/fpc-rtl-console
rtl_extra_UNIT=		lang/fpc-rtl-extra
rtl_generics_UNIT=	lang/fpc-rtl-generics
rtl_objpas_UNIT=	lang/fpc-rtl-objpas
rtl_unicode_UNIT=	lang/fpc-rtl-unicode
sdl_UNIT=	devel/fpc-sdl
svgalib_UNIT=	graphics/fpc-svgalib
symbolic_UNIT=	devel/fpc-symbolic
syslog_UNIT=	sysutils/fpc-syslog
unzip_UNIT=	archivers/fpc-unzip
users_UNIT=	sysutils/fpc-users
utmp_UNIT=	sysutils/fpc-utmp
uuid_UNIT=	sysutils/fpc-uuid
vcl_compat_UNIT=	graphics/fpc-vcl-compat
webidl_UNIT=	www/fpc-webidl
x11_UNIT=	x11/fpc-x11
xforms_UNIT=	x11-toolkits/fpc-xforms
zlib_UNIT=	devel/fpc-zlib

.endif

.if defined(USE_FPC)
.	for UNIT in ${USE_FPC}
.		if ${_FPC_ALL_UNITS:M${UNIT}} != ""
BUILD_DEPENDS+= ${MKINSTDIR}/${UNIT}.fpm:${${UNIT:S/-/_/}_UNIT}
.			if ${fpc_ARGS:Mrun} || ${fpc_ARGS:Mbase}
RUN_DEPENDS+=   ${MKINSTDIR}/${UNIT}.fpm:${${UNIT:S/-/_/}_UNIT}
.			endif
.		endif
.	endfor
.endif
