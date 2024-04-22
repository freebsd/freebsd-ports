PORTNAME=	crimson
PORTVERSION=	0.5.3
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://crimson.seul.org/files/
PKGNAMESUFFIX=	-fields

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tactical war game in the tradition of Battle Isle
WWW=		http://crimson.seul.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		gmake sdl
USE_SDL=	mixer sdl ttf

.include <bsd.port.mk>
