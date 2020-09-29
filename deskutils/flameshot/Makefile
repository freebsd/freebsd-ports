# Created by: Nicola Stanislao Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flameshot
PORTVERSION=	0.8.3
#PORTREVISION=	0
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Powerful yet simple to use screenshot software

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang gl qmake qt:5

CMAKE_INSTALL_PREFIX=	${STAGEDIR}/${PREFIX}

GH_ACCOUNT=	lupoDharkael

USE_GITHUB=	yes
USE_GL=		gl
USE_QT=		core dbus gui linguist network svg widgets \
		buildtools_build

.include <bsd.port.mk>
