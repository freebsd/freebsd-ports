# created by: Osamu Matsuda <omatsuda000@gmail.com>

PORTNAME=	qolibri
DISTVERSION=	2.1.4
PORTREVISION=	1
CATEGORIES=	japanese

MAINTAINER=	omatsuda000@gmail.com
COMMENT=	EPWING dictionary viewer
WWW=		https://github.com/ludios/qolibri/

LICENSE=	GPLv2

LIB_DEPENDS=	libeb.so:japanese/eb

USES=		cmake qt:5
USE_QT=		buildtools core declarative gui linguisttools location \
		multimedia network printsupport qmake webchannel webengine \
		widgets

USE_GITHUB=	yes
GH_ACCOUNT=	ludios

PLIST_FILES=	bin/qolibri

.include <bsd.port.mk>
