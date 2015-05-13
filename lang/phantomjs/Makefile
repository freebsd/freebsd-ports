# $FreeBSD$

PORTNAME=	phantomjs
PORTVERSION=	1.9.8
#PORTREVISION=	0
CATEGORIES=	lang
MASTER_SITES=	https://bitbucket.org/ariya/phantomjs/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Minimalistic, headless, WebKit-based, JavaScript-driven tool

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

PROJECTHOST=	phantomjs
USES=		gmake dos2unix pkgconfig zip
USE_GCC=	any
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLIST_FILES=	bin/phantomjs

do-build:
	cd ${WRKSRC} && ${SETENV} CC=${CC} CXX=${CXX} OSTYPE=freebsd MAKEFLAGS= PATH=${PATH} bash -x build.sh --jobs ${MAKE_JOBS_NUMBER} --confirm \
		--qt-config '-no-pch'

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} bin/phantomjs ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not link on sparc64
.endif

.include <bsd.port.post.mk>
