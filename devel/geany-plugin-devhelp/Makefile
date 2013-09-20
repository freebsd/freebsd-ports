# $FreeBSD$

PORTNAME=	geany-plugin-devhelp
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

LIB_DEPENDS=	wnck-1:${PORTSDIR}/x11-toolkits/libwnck \
		webkitgtk-1.0:${PORTSDIR}/www/webkit-gtk2

USE_GNOME=	gconf2

NO_STAGE=	yes
.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
