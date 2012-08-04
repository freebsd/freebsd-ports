# New ports collection makefile for:	boinc-astropulse
# Date created:				8 July 2009
# Whom:					Rene Ladan <rene@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	boinc-astropulse
PORTVERSION=	6.01
PORTREVISION=	2
CATEGORIES=	astro
MASTER_SITES=	ftp://rene-ladan.nl/pub/distfiles/
DISTNAME=	astropulse-svn-1280

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Astropulse for BOINC

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3 \
		${NONEXISTENT}:${PORTSDIR}/astro/boinc-setiathome-enhanced:patch
RUN_DEPENDS=	boinc_client:${PORTSDIR}/net/boinc-client
LIB_DEPENDS=	fftw3f:${PORTSDIR}/math/fftw3-float

USE_XZ=		yes
USE_AUTOTOOLS=	autoconf:env automake:env libtool
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
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

#OPTIONS=	X11		"Build screensaver (requires net/boinc-client with X11)" on

.include <bsd.port.pre.mk>
# stolen and adapted from bsd.port.mk
.if (${OSVERSION} >= 900000 && ${OSVERSION} < 900012) || ${OSVERSION} < 800505
BUILD_DEPENDS+=	${LOCALBASE}/bin/xz:${PORTSDIR}/archivers/xz
.endif

# TODO fix upstream
.if defined(WITHOUT_X11)
BROKEN=Currently Astropulse requires X11 to build
.endif

.if !defined(WITHOUT_X11)
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg \
		xcb:${PORTSDIR}/x11/libxcb
USE_GL=		gl glu glut
USE_XORG=	ice sm x11 xau xext xi xdamage xdmcp xfixes xmu xt xxf86vm
BUILD_DEPENDS+=	${LOCALBASE}/lib/libboinc_graphics2.a:${PORTSDIR}/net/boinc-client
PLIST_SUB+=	X11=""
.else
BUILD_DEPENDS+=	${LOCALBASE}/include/boinc/std_fixes.h:${PORTSDIR}/net/boinc-client
CONFIGURE_ARGS+=	--disable-graphics
PLIST_SUB+=	X11="@comment "
.endif

.if ${ARCH} == amd64 || ${ARCH} == i386
# comment out if world is built with clang and port with gcc
CFLAGS+=	-mtune=native
.endif

SETI_WORK!=	cd ${.CURDIR}/../boinc-setiathome-enhanced && ${MAKE} -V WRKSRC
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
		BOINC_CLIENT_HOME=${BOINC_CLIENT_HOME}

pre-configure:
	(cd ${WRKSRC} ; ./_autosetup)

do-install:
	${INSTALL} -d -o ${BOINC_CLIENT_USER} -g ${BOINC_CLIENT_GROUP} ${BOINC_CLIENT_HOME}/projects
	${INSTALL} -d -o ${BOINC_CLIENT_USER} -g ${BOINC_CLIENT_GROUP} \
	    ${BOINC_CLIENT_HOME}/projects/${SETI_SITE}
	${INSTALL_PROGRAM} -o ${BOINC_CLIENT_USER} -g ${BOINC_CLIENT_GROUP} \
	    ${WRKSRC}/${AP_BINARY} ${BOINC_CLIENT_HOME}/projects/${SETI_SITE}/
.if !defined(WITHOUT_X11)
	${INSTALL_PROGRAM} -o ${BOINC_CLIENT_USER} -g ${BOINC_CLIENT_GROUP} \
	    ${WRKSRC}/ap_graphics ${BOINC_CLIENT_HOME}/projects/${SETI_SITE}/
.endif

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
