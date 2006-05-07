# New ports collection makefile for:	viruskiller
# Date created:				13 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	viruskiller
DISTVERSION=	1.0-1
CATEGORIES=	games
MASTER_SITES=	http://www.parallelrealities.co.uk/download.php?type=zip&file=

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	An arcade game that relies on quick reflexes

FETCH_BEFORE_ARGS+=	-o ${DISTNAME}${EXTRACT_SUFX}

USE_GMAKE=	yes
USE_SDL=	image mixer sdl ttf

WRKSRC=		${WRKDIR}/${PORTNAME}-1.0

MAKEFILE=	makefile
MAKE_ENV=	CXX="${CXX}"

post-patch:
# Fix Makefile
	@${REINPLACE_CMD} -e 's|$$(PREFIX)/share/$$(PROG)|${DATADIR}| ; \
			s|$$(PREFIX)/share/doc/$$(PROG)|${DOCSDIR}| ; \
			s|sdl-config|${SDL_CONFIG}| ; \
			s|\(-Wall\)|${CFLAGS} \1|' \
				${WRKSRC}/${MAKEFILE}

# Fix SDL include statement
	@${REINPLACE_CMD} -e 's|\(#include.*\)SDL/\(SDL.*\)|\1\2|' \
				${WRKSRC}/src/*.cpp ${WRKSRC}/src/*.h

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	${RM} ${DOCSDIR}/LICENSE
.endif

.include <bsd.port.mk>
