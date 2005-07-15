# New ports collection makefile for:	starfighter
# Date created:				13 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	starfighter
DISTVERSION=	1.1-1
CATEGORIES=	games
MASTER_SITES=	http://www.parallelrealities.co.uk/download.php?type=zip&file=

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Chris Bainfield is fighting for the freedom of the galaxy

FETCH_BEFORE_ARGS+=	-o ${DISTNAME}${EXTRACT_SUFX}

USE_GMAKE=	yes
USE_SDL=	image mixer sdl
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-1.1

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on

MAKEFILE=	makefile
MAKE_ENV=	CXX="${CXX}"

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
	${RM} ${DOCSDIR}/LICENSE
.endif

.include <bsd.port.pre.mk>

post-patch:
# Fix Makefile
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}| ; \
			s|\(-Wall\)|${CFLAGS} \1|' \
				${WRKSRC}/${MAKEFILE}

# Fix SDL include statement
	@${REINPLACE_CMD} -e 's|\(#include.*\)SDL/\(SDL.*\)|\1\2|' \
				${WRKSRC}/code/*.cpp ${WRKSRC}/code/*.h

# Enable/disable compilation optimizations
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|-O3||g' ${WRKSRC}/${MAKEFILE}
.endif

.include <bsd.port.post.mk>
