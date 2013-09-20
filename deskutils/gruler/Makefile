# Created by: Piotr Smyrak <smyru@heron.pl>
# $FreeBSD$

PORTNAME=	gruler
PORTVERSION=	0.6
PORTREVISION=	10
CATEGORIES=	deskutils
MASTER_SITES=	http://linuxadvocate.org/projects/gruler/downloads/

MAINTAINER=	ps.ports@smyrak.com
COMMENT=	A simple customizable GTK screen ruler

USES=		pkgconfig
USE_GNOME=	gnomeprefix gnomehack libgnomeui libglade2
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -export-dynamic

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=""||' ${WRKSRC}/configure

.include <bsd.port.mk>
