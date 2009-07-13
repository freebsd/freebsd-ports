#
# $FreeBSD$
#
# bsd.fpc.mk - Support for FreePascal based ports.
#
# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# For FreeBSD committers:
# Please send all suggested changes to the maintainer instead of committing
# them to CVS yourself.
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

FPC_Include_MAINTAINER=	acm@FreeBSD.org
FPC_Pre_Include=	bsd.fpc.mk

DEFAULT_FPC_VER=	2.2.4
FPC_VER=		${DEFAULT_FPC_VER}

.if exists(${LOCALBASE}/bin/fpc)
FPC_CURRENT_VER!=	${LOCALBASE}/bin/fpc -iV
.	if ${FPC_CURRENT_VER} != ${FPC_VER}
IGNORE=	incompatible fpc ${FPC_CURRENT_VER} compiler, please install ${FPC_VER} version
.	endif
.endif

BUILD_DEPENDS+=		ppc386:${PORTSDIR}/lang/fpc

BUILDNAME=		${ARCH}-freebsd
UNITSDIR=		${LOCALBASE}/lib/fpc/${FPC_VER}/units/${BUILDNAME}

fpc-check-install:
check-makevars::
.if defined(UNITPREFIX) && defined(PKGNAMESUFFIX)
	@${ECHO_CMD} "#################################################################"
	@${ECHO_CMD} ""
	@${ECHO_CMD} " The following freepascal unit will be installed in your system: "
	@${ECHO_CMD} ""
	@${ECHO_CMD} " * ${UNITPREFIX}${PKGNAMESUFFIX:S/-//}			       "
	@${ECHO_CMD} ""
	@${ECHO_CMD} "#################################################################"
.endif

_FPC_ALL_UNITS=	aspell bfd cairo chm fcl-async fcl-base fcl-db fcl-fpcunit fcl-image \
		fcl-json fcl-net fcl-passrc fcl-process fcl-registry fcl-web fcl-xml fftw \
		fpmkunit fpgtk fv gdbint gdbm ggi gnome1 graph gtk1 gtk2 hash httpd13 httpd20 \
		httpd22 ibase iconvenc imagemagick imlib libcurl libgd libpng mysql ncurses numlib \
		odbc opengl openssl oracle pasjpeg paszlib pcap postgres pthreads pxlib \
		regexpr sdl sqlite svgalib symbolic syslog tcl unzip users utmp x11 xforms \
		zlib

.if defined(WANT_FPC_BASE)
.       if ${WANT_FPC_BASE:L} == "yes"
USE_FPC=	gdbint graph ibase hash httpd13 httpd20 httpd22 mysql odbc oracle \
		pasjpeg paszlib	pthreads postgres regexpr sqlite
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
ibase_UNIT=	databases/fpc-ibase
hash_UNIT=	security/fpc-hash
httpd13_UNIT=	www/fpc-httpd13
httpd20_UNIT=	www/fpc-httpd20
httpd22_UNIT=	www/fpc-httpd22
mysql_UNIT=	databases/fpc-mysql
odbc_UNIT=	databases/fpc-odbc
oracle_UNIT=	databases/fpc-oracle
pasjpeg_UNIT=	graphics/fpc-pasjpeg
paszlib_UNIT=	archivers/fpc-paszlib
pthreads_UNIT=	devel/fpc-pthreads
postgres_UNIT=	databases/fpc-postgres
regexpr_UNIT=	devel/fpc-regexpr
sqlite_UNIT=	databases/fpc-sqlite

# Extra units
aspell_UNIT=	textproc/fpc-aspell
bfd_UNIT=	devel/fpc-bfd
cairo_UNIT=	graphics/fpc-cairo
chm_UNIT=	misc/fpc-chm
fcl_async_UNIT=	devel/fpc-fcl-async
fcl_base_UNIT=	devel/fpc-fcl-base
fcl_db_UNIT=	devel/fpc-fcl-db
fcl_fpcunit_UNIT=	devel/fpc-fcl-fpcunit
fcl_image_UNIT=	devel/fpc-fcl-image
fcl_json_UNIT=	devel/fpc-fcl-json
fcl_net_UNIT=	devel/fpc-fcl-net
fcl_passrc_UNIT=	devel/fpc-fcl-passrc
fcl_process_UNIT=	devel/fpc-fcl-process
fcl_registry_UNIT=	devel/fpc-fcl-registry
fcl_web_UNIT=	devel/fpc-fcl-web
fcl_xml_UNIT=	devel/fpc-fcl-xml
fftw_UNIT=	math/fpc-fftw
fpmkunit_UNIT=	devel/fpc-fpmkunit
fpgtk_UNIT=	graphics/fpc-fpgtk
fv_UNIT=	devel/fpc-fv
gdbm_UNIT=	databases/fpc-gdbm
ggi_UNIT=	graphics/fpc-ggi
gnome1_UNIT=	x11-toolkits/fpc-gnome1
gtk1_UNIT=	x11-toolkits/fpc-gtk1
gtk2_UNIT=	x11-toolkits/fpc-gtk2
iconvenc_UNIT=	converters/fpc-iconvenc
imagemagick_UNIT=	graphics/fpc-imagemagick
imlib_UNIT=	graphics/fpc-imlib
libcurl_UNIT=	ftp/fpc-libcurl
libgd_UNIT=	graphics/fpc-libgd
libpng_UNIT=	graphics/fpc-libpng
ncurses_UNIT=	graphics/fpc-ncurses
numlib_UNIT=	math/fpc-numlib
opengl_UNIT=	graphics/fpc-opengl
openssl_UNIT=	security/fpc-openssl
pcap_UNIT=	net/fpc-pcap
pxlib_UNIT=	databases/fpc-pxlib
sdl_UNIT=	devel/fpc-sdl
svgalib_UNIT=	graphics/fpc-svgalib
symbolic_UNIT=	devel/fpc-symbolic
syslog_UNIT=	sysutils/fpc-syslog
tcl_UNIT=	lang/fpc-tcl
unzip_UNIT=	archivers/fpc-unzip
users_UNIT=	sysutils/fpc-users
utmp_UNIT=	sysutils/fpc-utmp
x11_UNIT=	x11/fpc-x11
xforms_UNIT=	x11-toolkits/fpc-xforms
zlib_UNIT=	devel/fpc-zlib

.endif

.if defined(_POSTMKINCLUDED) && defined(USE_FPC)

.	for UNITS in ${USE_FPC}
.		if ${_FPC_ALL_UNITS:M${UNITS}}!=""
BUILD_DEPENDS+=	${UNITSDIR}/${UNITS}/Package.fpc:${PORTSDIR}/${${UNITS:S/-/_/}_UNIT}
RUN_DEPENDS+=	${UNITSDIR}/${UNITS}/Package.fpc:${PORTSDIR}/${${UNITS:S/-/_/}_UNIT}
security-check: fpc-check-install
.		endif
.	endfor
.endif

#.endif
# End of bsd.fpc.mk file
