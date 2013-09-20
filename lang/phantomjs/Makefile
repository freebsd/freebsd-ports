# $FreeBSD$

PORTNAME=	phantomjs
PORTVERSION=	1.9.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Minimalistic, headless, WebKit-based, JavaScript-driven tool

LICENSE=	BSD

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

PROJECTHOST=	phantomjs
USE_ZIP=	YES
USE_GMAKE=	YES
USE_DOS2UNIX=	YES
USE_QT4=	moc qmake gui webkit rcc
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_STAGE=	yes
do-build:
	cd ${WRKSRC} && ${SETENV} OSTYPE=freebsd MAKEFLAGS= bash -x build.sh --jobs 2 --confirm

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} bin/phantomjs ${PREFIX}/bin/

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not link on sparc64
.endif

.include <bsd.port.post.mk>
