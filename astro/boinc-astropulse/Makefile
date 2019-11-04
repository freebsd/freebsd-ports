# Created by: rene
# $FreeBSD$

PORTNAME=	boinc-astropulse
PORTVERSION=	6.01
PORTREVISION=	14
CATEGORIES=	astro
MASTER_SITES=	LOCAL/rene
DISTNAME=	astropulse-svn-1702 # modified archive, see leftout in top directory

MAINTAINER=	ler@FreeBSD.org
COMMENT=	Astropulse for BOINC

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=		fails to compile: call to abs is ambiguous

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3 \
		${NONEXISTENT}:astro/boinc-setiathome:configure
RUN_DEPENDS=	boinc_client:net/boinc-client
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float

USES=		autoreconf compiler:c++11-lang gmake libtool pkgconfig tar:xz

GNU_CONFIGURE=	yes

WRKSRC_SUBDIR=		client

CPPFLAGS+=	-I${LOCALBASE}/include/boinc -I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lexecinfo

# these must match settings in ${PORTSDIR}/net/boinc-client/Makefile
BOINC_CLIENT_USER?=	boinc
BOINC_CLIENT_GROUP?=	boinc
BOINC_CLIENT_HOME?=	/var/db/boinc

SETI_WORK!=	cd ${.CURDIR}/../boinc-setiathome && ${MAKE} -V WRKSRC
CONFIGURE_ENV=	BOINCDIR="${NONEXISTENT}" \
		BOINC_DIR="${NONEXISTENT}" \
		SETI_BOINC_DIR="${SETI_WORK}"
CONFIGURE_ARGS=	--disable-static-client \
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
PLIST_SUB=	AP_BINARY=${AP_BINARY} \
		SETI_SITE=${SETI_SITE} \
		BOINC_CLIENT_HOME=${BOINC_CLIENT_HOME} \
		BOINC_CLIENT_USER=${BOINC_CLIENT_USER} \
		BOINC_CLIENT_GROUP=${BOINC_CLIENT_GROUP}

OPTIONS_DEFINE=	X11
OPTIONS_SUB=	yes

X11_DESC=		Build screensaver (requires net/boinc-client with X11)
X11_BUILD_DEPENDS=	${LOCALBASE}/lib/libboinc_graphics2.a:net/boinc-client
X11_USES=		gl jpeg xorg
X11_USE=		GL=gl,glu,glut \
			XORG=ice,sm,x11,xau,xcb,xext,xi,xdamage,xdmcp,xfixes,xmu,xt,xxf86vm
X11_CONFIGURE_ENABLE=	graphics
X11_BUILD_DEPENDS_OFF=	${LOCALBASE}/include/boinc/std_fixes.h:net/boinc-client

do-install:
	@${MKDIR} ${STAGEDIR}${BOINC_CLIENT_HOME}/projects/${SETI_SITE}
	${INSTALL_PROGRAM} ${WRKSRC}/${AP_BINARY} \
		${STAGEDIR}${BOINC_CLIENT_HOME}/projects/${SETI_SITE}/

do-install-X11-on:
	${INSTALL_PROGRAM} ${WRKSRC}/ap_graphics \
		${STAGEDIR}${BOINC_CLIENT_HOME}/projects/${SETI_SITE}/

.include <bsd.port.mk>
