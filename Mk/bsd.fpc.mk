#
# $FreeBSD$
#
# bsd.fpc.mk - Support for FreePascal based ports.
#
# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# For FreeBSD committers:
# Please send all suggested changes to the maintainer instead of committing
# them to SVN yourself.
#
# USE_FPC		- If you set this to "yes", this automatically will install
#			  free pascal compiler, if you need install additional fpc
#			  units, they can be listed there (USE_FPC= gtk x11 opengl).
#
# WANT_FPC_BASE		- If you set this to "yes", this automatically will install
#			  all base units of fpc (gdbint graph ibase libasync hash 
#			  httpd mysql netdb odbc oracle pasjpeg paszlib pthreads 
#		 	  postgres regexpr and sqlite).
#
# WANT_FPC_ALL		- If you set this to "yes", this automatically will install
#			  all free pascal units.
#
#

.if !defined(_FPCMKINCLUDED)

_FPCMKINCLUDED=	yes

.include "${PORTSDIR}/Mk/bsd.default-versions.mk"

.if defined(DEFAULT_FPC_VER)
WARNING+=	"DEFAULT_FPC_VER is defined, consider using DEFAULT_VERSIONS=fpc=${DEFAULT_FPC_VER} instead"
.endif

FPC_Include_MAINTAINER=	acm@FreeBSD.org
FPC_Pre_Include=	bsd.fpc.mk

DEFAULT_FPC_VER=	${FPC_DEFAULT}
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

BUILD_DEPENDS+=		${PPNAME}:${PORTSDIR}/lang/fpc

BUILDNAME=		${FPC_ARCH}-freebsd
UNITSDIR=		${LOCALBASE}/lib/fpc/${FPC_VER}/units/${BUILDNAME}

_FPC_ALL_UNITS=	a52 aspell bfd bzip2 cairo chm dblib dbus dts fastcgi fcl-async fcl-base \
		fcl-db fcl-extra fcl-fpcunit fcl-image fcl-js fcl-json fcl-net fcl-passrc \
		fcl-process fcl-registry fcl-res fcl-web fcl-xml fftw fpgtk fpindexer \
		fpmkunit fppkg fv gdbint gdbm ggi gmp gnome1 graph gtk1 gtk2 hash \
		hermes httpd22 httpd24 ibase iconvenc imagemagick imlib ldap libcurl libgd \
		libpng libvlc libxml2 lua mad matroska modplug mysql ncurses newt numlib \
		odbc oggvorbis openal opengl openssl oracle pasjpeg paszlib pcap \
		postgres proj4 pthreads pxlib regexpr rexx rsvg sdl sndfile sqlite \
		svgalib symbolic syslog tcl unzip users utmp uuid x11 xforms zlib

_FPC_CFG_UNITS=	fastcgi fcl-web

.if defined(WANT_FPC_BASE)
.       if ${WANT_FPC_BASE:L} == "yes"
USE_FPC=	gdbint graph hash httpd22 httpd24 ibase mysql odbc oracle pasjpeg paszlib \
		postgres pthreads regexpr sqlite
.       else
IGNORE= unknown value, please use "yes" instead of
.       endif
.endif

.if defined(WANT_FPC_ALL)
.	if ${WANT_FPC_ALL:L} == "yes"
USE_FPC=	${_FPC_ALL_UNITS}
.	else
IGNORE=	unknown value, please use "yes" instead of
.	endif
.endif

.if ${USE_FPC:L} != "yes"
.	for UNITS in ${USE_FPC}
.		if ${_FPC_ALL_UNITS:M${UNITS}}==""
IGNORE= cannot install: unknown FPC unit ${UNITS}
.		endif
.	endfor
.endif

# Base units
gdbint_UNIT=	devel/fpc-gdbint
graph_UNIT=	graphics/fpc-graph
hash_UNIT=	security/fpc-hash
httpd22_UNIT=	www/fpc-httpd22
httpd24_UNIT=	www/fpc-httpd24
ibase_UNIT=	databases/fpc-ibase
mysql_UNIT=	databases/fpc-mysql
odbc_UNIT=	databases/fpc-odbc
oracle_UNIT=	databases/fpc-oracle
pasjpeg_UNIT=	graphics/fpc-pasjpeg
paszlib_UNIT=	archivers/fpc-paszlib
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
fcl_process_UNIT=	devel/fpc-fcl-process
fcl_registry_UNIT=	devel/fpc-fcl-registry
fcl_res_UNIT=	devel/fpc-fcl-res
fcl_web_UNIT=	devel/fpc-fcl-web
fcl_xml_UNIT=	devel/fpc-fcl-xml
fftw_UNIT=	math/fpc-fftw
fpindexer_UNIT=	databases/fpc-fpindexer
fpmkunit_UNIT=	devel/fpc-fpmkunit
fpgtk_UNIT=	graphics/fpc-fpgtk
fppkg_UNIT=	devel/fpc-fppkg
fpvectorial_UNIT=	graphics/fpc-fpvectorial
fv_UNIT=	devel/fpc-fv
hermes_UNIT=	graphics/fpc-hermes
gdbm_UNIT=	databases/fpc-gdbm
ggi_UNIT=	graphics/fpc-ggi
gmp_UNIT=	math/fpc-gmp
gnome1_UNIT=	x11-toolkits/fpc-gnome1
gtk1_UNIT=	x11-toolkits/fpc-gtk1
gtk2_UNIT=	x11-toolkits/fpc-gtk2
iconvenc_UNIT=	converters/fpc-iconvenc
imagemagick_UNIT=	graphics/fpc-imagemagick
imlib_UNIT=	graphics/fpc-imlib
ldap_UNIT=	net/fpc-ldap
libcurl_UNIT=	ftp/fpc-libcurl
libgd_UNIT=	graphics/fpc-libgd
libpng_UNIT=	graphics/fpc-libpng
libvlc_UNIT=	multimedia/fpc-libvlc
libxml2_UNIT=	textproc/fpc-libxml2
lua_UNIT=	lang/fpc-lua
mad_UNIT=	audio/fpc-mad
matroska_UNIT=	multimedia/fpc-matroska
modplug_UNIT=	audio/fpc-modplug
newt_UNIT=	devel/fpc-newt
ncurses_UNIT=	graphics/fpc-ncurses
numlib_UNIT=	math/fpc-numlib
oggvorbis_UNIT=	audio/fpc-oggvorbis
openal_UNIT=	audio/fpc-openal
opengl_UNIT=	graphics/fpc-opengl
openssl_UNIT=	security/fpc-openssl
pcap_UNIT=	net/fpc-pcap
proj4_UNIT=	graphics/fpc-proj4
pxlib_UNIT=	databases/fpc-pxlib
rexx_UNIT=	lang/fpc-rexx
rsvg_UNIT=	graphics/fpc-rsvg
sdl_UNIT=	devel/fpc-sdl
sndfile_UNIT=	audio/fpc-sndfile
svgalib_UNIT=	graphics/fpc-svgalib
symbolic_UNIT=	devel/fpc-symbolic
syslog_UNIT=	sysutils/fpc-syslog
tcl_UNIT=	lang/fpc-tcl
unzip_UNIT=	archivers/fpc-unzip
users_UNIT=	sysutils/fpc-users
utmp_UNIT=	sysutils/fpc-utmp
uuid_UNIT=	sysutils/fpc-uuid
x11_UNIT=	x11/fpc-x11
xforms_UNIT=	x11-toolkits/fpc-xforms
zlib_UNIT=	devel/fpc-zlib

.endif

.if defined(_POSTMKINCLUDED) && defined(USE_FPC)
.	for UNITS in ${USE_FPC}
.		if ${_FPC_ALL_UNITS:M${UNITS}}!=""
.			if ${_FPC_CFG_UNITS:M${UNITS}}!=""
BUILD_DEPENDS+= ${UNITSDIR}/${UNITS}/fpunits.cfg:${PORTSDIR}/${${UNITS:S/-/_/}_UNIT}
RUN_DEPENDS+=   ${UNITSDIR}/${UNITS}/fpunits.cfg:${PORTSDIR}/${${UNITS:S/-/_/}_UNIT}
.			else
BUILD_DEPENDS+= ${UNITSDIR}/${UNITS}/Package.fpc:${PORTSDIR}/${${UNITS:S/-/_/}_UNIT}
RUN_DEPENDS+=   ${UNITSDIR}/${UNITS}/Package.fpc:${PORTSDIR}/${${UNITS:S/-/_/}_UNIT}
.			endif

security-check: fpc-check-install
.		endif
.	endfor

fpc-check-install:
.if defined(UNITPREFIX) && defined(PKGNAMESUFFIX)
	@${ECHO_CMD} "#################################################################"
	@${ECHO_CMD} ""
	@${ECHO_CMD} " The following freepascal unit has been installed in your system:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} " * ${UNITPREFIX}${PKGNAMESUFFIX:S/-//}                           "
	@${ECHO_CMD} ""
	@${ECHO_CMD} "#################################################################"
.endif

.endif
#.endif
# End of bsd.fpc.mk file
