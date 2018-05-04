# Created by: Piotr Smyrak <smyru@heron.pl>
# $FreeBSD$

PORTNAME=	gruler
PORTVERSION=	0.6
PORTREVISION=	13
CATEGORIES=	deskutils
MASTER_SITES=	https://BSDforge.com/projects/source/deskutils/gruler/

MAINTAINER=	ps.ports@smyrak.com
COMMENT=	Simple customizable GTK screen ruler

USES=		pkgconfig pathfix libtool
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix libgnomeui libglade2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -export-dynamic

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=""||' ${WRKSRC}/configure

.include <bsd.port.mk>
