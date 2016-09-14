# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	supertux
PORTVERSION=	0.1.3
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Side-scroller game similar to Super Mario Brothers

BROKEN=		Unfetchable (google code has gone away)

USES=		gmake tar:bzip2
USE_SDL=	image mixer
USE_GL=		gl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=		--disable-debug

PORTSCOUT=	limit:^0\.1

post-patch:
	@${REINPLACE_CMD} -e 's,Menu::,,' ${WRKSRC}/src/menu.h

.include <bsd.port.mk>
