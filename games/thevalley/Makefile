# Created by: Edwin Groothuis
# $FreeBSD$

PORTNAME=	thevalley
PORTVERSION=	0.98
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://www.autismuk.freeserve.co.uk/
DISTNAME=	valley-${PORTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	The Valley is a rewrite of an old RPG from the early 1980s

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_SDL=	sdl
USES=		libtool perl5
USE_PERL5=	build
CXXFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm

PLIST_FILES=	bin/valley

.include <bsd.port.mk>
