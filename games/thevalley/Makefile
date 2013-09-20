# Created by: Edwin Groothuis
# $FreeBSD$

PORTNAME=	thevalley
PORTVERSION=	0.98
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.autismuk.freeserve.co.uk/
DISTNAME=	valley-${PORTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	The Valley is a rewrite of an old RPG from the early 1980s

USE_AUTOTOOLS=	libtool
HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_SDL=	sdl
USES=		perl5
USE_PERL5=	build
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CXXFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include

PLIST_FILES=	bin/valley

NO_STAGE=	yes
post-configure:
	${REINPLACE_CMD} \
		-e 's,^LIBTOOL =.*,LIBTOOL= $$(SHELL) ${LIBTOOL} --silent,' \
		-e 's,^transform =.*,transform = s\,^\,\,,' \
		${WRKSRC}/valley/Makefile

.include <bsd.port.mk>
