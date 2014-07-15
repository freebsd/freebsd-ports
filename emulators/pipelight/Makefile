# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pipelight
DISTVERSION=	0.2.7.1
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	https://bitbucket.org/mmueller2012/pipelight/get/
DISTNAME=	v${DISTVERSION}

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Wrapper for using windows plugins in web browsers

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/gpg2:${PORTSDIR}/security/gnupg
LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget \
		${LOCALBASE}/bin/zenity:${PORTSDIR}/x11/zenity \
		${LOCALBASE}/bin/cabextract:${PORTSDIR}/archivers/cabextract \
		${LOCALBASE}/bin/flock:${PORTSDIR}/sysutils/flock \
		${LOCALBASE}/bin/gpg2:${PORTSDIR}/security/gnupg

WRKSRC=		${WRKDIR}/mmueller2012-pipelight-e2362eb15df6
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--verbose --wine-path=${LOCALBASE}/bin/wine --win32-prebuilt \
		--win64-prebuilt --moz-plugin-path=${LOCALBASE}/lib/browser_plugins
USES=		compiler:c11 gmake
MAKE_JOBS_UNSAFE=yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	${LOCALBASE}/bin/wine:${PORTSDIR}/emulators/wine-devel
RUN_DEPENDS+=	${LOCALBASE}/bin/wine:${PORTSDIR}/emulators/wine-devel
.elif ${ARCH} == "amd64"
BUILD_DEPENDS+=	${LOCALBASE}/bin/wine:${PORTSDIR}/emulators/i386-wine-devel
RUN_DEPENDS+=	${LOCALBASE}/bin/wine:${PORTSDIR}/emulators/i386-wine-devel
.endif

pre-configure:
	${REINPLACE_CMD} "s|DISTVERSION|v${DISTVERSION}|g" ${WRKSRC}/src/windows/Makefile
	${REINPLACE_CMD} "s|DISTVERSION|v${DISTVERSION}|g" ${WRKSRC}/src/winecheck/Makefile
	${REINPLACE_CMD} "s|/share/man/man1|/man/man1|g" ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
