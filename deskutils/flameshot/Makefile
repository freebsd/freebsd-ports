# Created by: Nicola Stanislao Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flameshot
PORTVERSION=	0.6.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Powerful yet simple to use screenshot software

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gl qmake qt:5

GH_ACCOUNT=	lupoDharkael

INSTALL_ICONS=	yes

USE_GITHUB=	yes
USE_GL=		gl
USE_QT=		core dbus gui linguist network svg widgets \
		buildtools_build

.include <bsd.port.mk>
