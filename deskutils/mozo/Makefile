# Created by: FreeBSD GNOME Team
# $FreeBSD$

PORTNAME=	mozo
PORTVERSION=	1.12.0
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Editor for the freedesktop.org menu specification

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig python:2 tar:xz
USE_MATE=	menus
USE_GNOME=	intltool pygobject pygtk2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
	    ${WRKSRC}/Mozo/util.py

.include <bsd.port.mk>
