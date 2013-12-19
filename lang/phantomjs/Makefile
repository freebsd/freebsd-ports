# $FreeBSD$

PORTNAME=	phantomjs
PORTVERSION=	1.9.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Minimalistic, headless, WebKit-based, JavaScript-driven tool

LICENSE=	BSD

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

PROJECTHOST=	phantomjs
USES=		gmake dos2unix
USE_ZIP=	YES
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-build:
	cd ${WRKSRC} && ${SETENV} OSTYPE=freebsd MAKEFLAGS= bash -x build.sh --jobs ${MAKE_JOBS_NUMBER} --confirm

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} bin/phantomjs ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not link on sparc64
.endif

.include <bsd.port.post.mk>
