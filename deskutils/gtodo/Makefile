# $FreeBSD$

PORTNAME=	gtodo
PORTVERSION=	0.14
PORTREVISION=	14
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk2 Todo list manager

USES=		pathfix gettext gmake pkgconfig
USE_GNOME=	gnomeprefix gnomevfs2 intltool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gtodo.schemas

post-patch:
	${REINPLACE_CMD} '/GCONF_CONFIG_SOURCE=/d' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
