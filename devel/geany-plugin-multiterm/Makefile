# $FreeBSD$

PORTNAME=	geany-plugin
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
USE_GNOME=	vte

GEANY_PLUGIN=	multiterm

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
