# Created by: Piotr Smyrak <smyru@heron.pl>
# $FreeBSD$

PORTNAME=	gruler
PORTVERSION=	0.6
PORTREVISION=	10
CATEGORIES=	deskutils
MASTER_SITES=	http://linuxadvocate.org/projects/gruler/downloads/

MAINTAINER=	ps.ports@smyrak.com
COMMENT=	Simple customizable GTK screen ruler

USES=		pkgconfig pathfix
USE_GNOME=	gnomeprefix libgnomeui libglade2
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -export-dynamic

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=""||' ${WRKSRC}/configure

.include <bsd.port.mk>
