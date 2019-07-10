# $FreeBSD$

PORTNAME=	bsequencer
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3-16
DISTVERSIONSUFFIX=	-g49dc212
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi channel MIDI step sequencer LV2 plugin

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		gmake gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	sjaehn
GH_PROJECT=	BSEQuencer
USE_GCC=	any # see https://github.com/sjaehn/BSEQuencer/issues/7
USE_GNOME=	cairo
USE_XORG=	x11

MAKEFILE=	makefile

.include <bsd.port.mk>
