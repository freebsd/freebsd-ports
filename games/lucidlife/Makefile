# Created by: Marcin Wisnicki <mwisnicki+freebsd@gmail.com>
# $FreeBSD$

PORTNAME=	lucidlife
PORTVERSION=	0.9.2
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org:9090/~jcspray/LucidLife/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 implementation of Conway's Game of Life

BROKEN=		unfetchable

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake pkgconfig
USE_GNOME=	gtk20 gnomevfs2 intlhack
USE_XORG=	x11
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} '/^GNOME_MODULES=/s/"$$/ x11"/' ${WRKSRC}/configure

.include <bsd.port.mk>
