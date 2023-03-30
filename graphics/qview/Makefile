PORTNAME=	qview
PORTVERSION=	5.0
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/jurplel/qView/releases/download/${PORTVERSION}/
DISTNAME=	qView-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Practical and minimal image viewer
WWW=		https://interversehq.com/qview/

LICENSE=	GPLv3

USES=		desktop-file-utils qmake qt:5
USE_QT=		buildtools:build concurrent:build linguisttools:build \
		core gui network widgets imageformats:run

WRKSRC=		${WRKDIR}/qView

.include <bsd.port.mk>
