# Created by: Andrey Slusar <anray@FreeBSD.org>

PORTNAME=	imagick
PORTVERSION=	3.5.1
CATEGORIES=	graphics

MAINTAINER=	000.fbsd@quip.cz
COMMENT?=	PHP wrapper to the ImageMagick/GraphicsMagick library version 6

LICENSE=	PHP301

USES=		cpe php:pecl localbase

CPE_VENDOR=	php

CONFLICTS_INSTALL?=	${PKGNAMEPREFIX}${PORTNAME}-im7

OPTIONS_DEFINE=	X11

X11_USES?=		magick:6
X11_USES_OFF?=		magick:6,nox11

CONFIGURE_ARGS=	--with-imagick=${LOCALBASE}

.include <bsd.port.mk>
