# $FreeBSD$

PORTNAME=	geany-plugin-multiterm
PORTVERSION=	${GEANY_VER}
PKGNAMESUFFIX=	-gtk2
CATEGORIES=	devel

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgeany.so:devel/geany@gtk2

FLAVORS=	# intentionally left empty

USE_GNOME=	vte
USE_XORG=	x11 xext

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
