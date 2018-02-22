# Created by: FreeBSD GNOME Team
# $FreeBSD$

PORTNAME=	mozo
PORTVERSION=	1.18.0
PORTREVISION=	1
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Editor for the freedesktop.org menu specification

PORTSCOUT=	limitw:1,even

USES=		gettext gmake localbase pathfix pkgconfig \
		python:2.7 tar:xz
USE_MATE=	menus
USE_GNOME=	gtk30 intltool pygobject3
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
	    ${WRKSRC}/Mozo/util.py

.include <bsd.port.mk>
