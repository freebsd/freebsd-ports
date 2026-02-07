PORTNAME=	qview
PORTVERSION=	6.1
PORTREVISION=	1
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

OPTIONS_DEFINE=	KF5
OPTIONS_DEFAULT=	KF5

KF5_DESC=	HEIF and AVIF support (via kimageformats)
KF5_USES=	kde:5
KF5_USE=	KDE=kimageformats:run

.include <bsd.port.mk>
