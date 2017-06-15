# Created by: rene
# $FreeBSD$

PORTNAME=	boinc-setiathome-v7
PORTVERSION=	7.00
PORTREVISION=	6
CATEGORIES=	astro
MASTER_SITES=	LOCAL/rene
DISTNAME=	setiathome-svn-1924 # modified archive, see leftout in top directory

MAINTAINER=	ler@FreeBSD.org
COMMENT=	Setiathome Enhanced for BOINC

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
RUN_DEPENDS=	boinc_client:net/boinc-client
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float

USES=		tar:xz gmake pkgconfig
USE_AUTOTOOLS=	autoconf:env automake:env
GNU_CONFIGURE=	yes

CFLAGS+=	-O2 -I${LOCALBASE}/include/boinc -I${LOCALBASE}/include \
		-L${LOCALBASE}/lib
.if defined(CPUTYPE)
CFLAGS+=	-march=${CPUTYPE}
.endif

# these must match settings in ${PORTSDIR}/net/boinc-client/Makefile
BOINC_CLIENT_USER?=	boinc
BOINC_CLIENT_GROUP?=	boinc
BOINC_CLIENT_HOME?=	/var/db/boinc

OPTIONS_DEFINE=	X11

X11_DESC=	Build screensaver (requires net/boinc-client with X11)

OPTIONS_SUB=	yes

X11_BUILD_DEPENDS=	${LOCALBASE}/lib/libboinc_graphics2.a:net/boinc-client
X11_USES=		jpeg
X11_USE=		GL=gl,glu,glut \
			XORG=ice,sm,x11,xau,xcb,xext,xi,xdamage,xdmcp,xfixes,xmu,xt,xxf86vm
X11_CONFIGURE_ENABLE=	graphics

X11_BUILD_DEPENDS_OFF=	${LOCALBASE}/include/boinc/std_fixes.h:net/boinc-client

CFLAGS_i386=	-mtune=native
CFLAGS_amd64=	-mtune=native

.if !empty(MACHINE_CPU:Maltivec)
CONFIGURE_ARGS+=	--enable-altivec
.endif

CONFIGURE_ENV+=	BOINCDIR="${NONEXISTENT}"

CONFIGURE_ARGS+=	--disable-static-client --disable-server \
			--disable-tests \
			--with-boinc-platform=${ARCH}-portbld-freebsd

SETI_SITE=	setiathome.berkeley.edu
SETI_BINARY=	setiathome-${PORTVERSION:S/.0/./}.${ARCH}-portbld-freebsd

SUB_FILES=	pkg-deinstall pkg-install pkg-message
SUB_LIST=	SETI_BINARY=${SETI_BINARY} \
		SETI_SITE=${SETI_SITE} \
		SETI_VERSION=${PORTVERSION:S/.//} \
		BOINC_CLIENT_HOME=${BOINC_CLIENT_HOME} \
		BOINC_CLIENT_USER=${BOINC_CLIENT_USER} \
		BOINC_CLIENT_GROUP=${BOINC_CLIENT_GROUP}
PLIST_SUB+=	PREFIX=${PREFIX} \
		SETI_BINARY=${SETI_BINARY} \
		SETI_SITE=${SETI_SITE} \
		BOINC_CLIENT_HOME=${BOINC_CLIENT_HOME} \
		BOINC_CLIENT_USER=${BOINC_CLIENT_USER} \
		BOINC_CLIENT_GROUP=${BOINC_CLIENT_GROUP}

BROKEN_powerpc64=	Does not build

# str_replace.h is included in newer versions of net/boinc-client,
# but it is not needed on FreeBSD
post-patch:
	${REINPLACE_CMD} -E -e "s|#include \"str_replace.h\"||" \
		${WRKSRC}/client/main.cpp \
		${WRKSRC}/client/sah_gfx.cpp \
		${WRKSRC}/client/seti.cpp \
		${WRKSRC}/client/timecvt.cpp \
		${WRKSRC}/db/xml_util.cpp

pre-configure:
	(cd ${WRKSRC} ; ./_autosetup)

do-install:
	${INSTALL} -d ${STAGEDIR}${BOINC_CLIENT_HOME}/projects
	${INSTALL} -d ${STAGEDIR}${BOINC_CLIENT_HOME}/projects/${SETI_SITE}
	${INSTALL_PROGRAM} ${WRKSRC}/client/${SETI_BINARY} \
	    ${STAGEDIR}${BOINC_CLIENT_HOME}/projects/${SETI_SITE}/
do-install-X11-on:
	${INSTALL_PROGRAM} ${WRKSRC}/client/seti_graphics \
	    ${STAGEDIR}${BOINC_CLIENT_HOME}/projects/${SETI_SITE}/

.include <bsd.port.mk>
