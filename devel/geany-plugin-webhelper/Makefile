# $FreeBSD$

PORTNAME=	geany-plugin
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

LIB_DEPENDS=	webkitgtk-1.0:${PORTSDIR}/www/webkit-gtk2

GEANY_PLUGIN=	webhelper

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
