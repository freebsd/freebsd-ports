# $FreeBSD$

PORTNAME=	geany-plugin
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

LIB_DEPENDS=	wnck-1:${PORTSDIR}/x11-toolkits/libwnck \
		webkitgtk-1.0:${PORTSDIR}/www/webkit-gtk2

USE_GNOME=	gconf2

GEANY_PLUGIN=	devhelp

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
