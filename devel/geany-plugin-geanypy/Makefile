# $FreeBSD$

PORTNAME=	geany-plugin-geanypy
PORTVERSION=	${GEANY_VER}
PKGNAMESUFFIX=	-gtk2
CATEGORIES=	devel

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

LIB_DEPENDS=	libgeany.so:devel/geany@gtk2

FLAVORS=	# intentionally left empty

USES=		python:2.7
USE_GNOME=	pygtk2

OPTIONS_DEFINE=	DOCS

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
