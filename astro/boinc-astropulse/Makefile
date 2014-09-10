# Created by: rene
# $FreeBSD$

PORTNAME=	boinc-astropulse
PORTVERSION=	6.01
PORTREVISION=	9
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://rene-ladan.nl/pub/distfiles/
DISTNAME=	astropulse-svn-1702 # modified archive, see leftout in top directory
MASTER_SITE_SUBDIR=rene

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Astropulse for BOINC

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3 \
		${NONEXISTENT}:${PORTSDIR}/astro/boinc-setiathome-v7:patch
RUN_DEPENDS=	boinc_client:${PORTSDIR}/net/boinc-client
LIB_DEPENDS=	libfftw3f.so:${PORTSDIR}/math/fftw3-float

USES=		tar:xz gmake pkgconfig
USE_AUTOTOOLS=	autoconf:env automake:env libtool
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/client

CFLAGS+=	-O2 -I${LOCALBASE}/include/boinc -I${LOCALBASE}/include \
		-L${LOCALBASE}/lib
.if defined(CPUTYPE)
CFLAGS+=	-march=${CPUTYPE}
.endif

# these must match settings in ${PORTSDIR}/net/boinc-client/Makefile
BOINC_CLIENT_USER?=	boinc
BOINC_CLIENT_GROUP?=	nobody
BOINC_CLIENT_HOME?=	/var/db/boinc

OPTIONS_DEFINE=	X11
X11_DESC=	Build screensaver (requires net/boinc-client with X11)

OPTIONS_SUB=	yes

X11_BUILD_DEPENDS=	${LOCALBASE}/lib/libboinc_graphics2.a:${PORTSDIR}/net/boinc-client
X11_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg
X11_USE=		GL=gl,glu,glut \
			XORG=ice,sm,x11,xau,xcb,xext,xi,xdamage,xdmcp,xfixes,xmu,xt,xxf86vm
X11_CONFIGURE_ENABLE=	graphics

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MX11}
BUILD_DEPENDS+=	${LOCALBASE}/include/boinc/std_fixes.h:${PORTSDIR}/net/boinc-client
.endif

.if ${ARCH} == amd64 || ${ARCH} == i386
# comment out if world is built with clang and port with gcc
CFLAGS+=	-mtune=native
.endif

SETI_WORK!=	cd ${.CURDIR}/../boinc-setiathome-v7 && ${MAKE} -V WRKSRC
CONFIGURE_ENV+=	BOINCDIR="${NONEXISTENT}" \
		BOINC_DIR="${NONEXISTENT}" \
		SETI_BOINC_DIR="${SETI_WORK}"
CONFIGURE_ARGS+=	--disable-static-client \
			--with-boinc-platform=${ARCH}-portbld-freebsd

SETI_SITE=	setiathome.berkeley.edu
AP_BINARY=	astropulse-${PORTVERSION:S/.0/./}.${ARCH}-portbld-freebsd

SUB_FILES=	pkg-deinstall pkg-install pkg-message
SUB_LIST=	AP_BINARY=${AP_BINARY} \
		AP_VERSION=${PORTVERSION:S/.//} \
		SETI_SITE=${SETI_SITE} \
		BOINC_CLIENT_HOME=${BOINC_CLIENT_HOME} \
		BOINC_CLIENT_USER=${BOINC_CLIENT_USER} \
		BOINC_CLIENT_GROUP=${BOINC_CLIENT_GROUP}
PLIST_SUB+=	AP_BINARY=${AP_BINARY} \
		SETI_SITE=${SETI_SITE} \
		BOINC_CLIENT_HOME=${BOINC_CLIENT_HOME} \
		BOINC_CLIENT_USER=${BOINC_CLIENT_USER} \
		BOINC_CLIENT_GROUP=${BOINC_CLIENT_GROUP}

pre-configure:
	(cd ${WRKSRC} ; ./_autosetup)

do-install:
	${INSTALL} -d ${STAGEDIR}${BOINC_CLIENT_HOME}/projects
	${INSTALL} -d ${STAGEDIR}${BOINC_CLIENT_HOME}/projects/${SETI_SITE}
	${INSTALL_PROGRAM} ${WRKSRC}/${AP_BINARY} \
	    ${STAGEDIR}${BOINC_CLIENT_HOME}/projects/${SETI_SITE}/
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${WRKSRC}/ap_graphics \
	    ${STAGEDIR}${BOINC_CLIENT_HOME}/projects/${SETI_SITE}/
.endif

.include <bsd.port.mk>
