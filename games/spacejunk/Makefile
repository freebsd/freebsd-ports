# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spacejunk
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A video game about traveling in 2D planetary systems

GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer image
MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	spacejunk

PORTDOCS=	*

DESKTOP_ENTRIES=	"Spacejunk" \
			"Collect garbage by navigating through the gravitational fields of planets and stars" \
			"" \
			"spacejunk" \
			"Game;ArcadeGame;" \
			false

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Doesn't compile on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/src/gem-uta.c \
		${WRKSRC}/libinfo/gem-uta.c
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/&|' ${WRKSRC}/src/*.c*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/spacejunk ${PREFIX}/libexec/
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} 'data config.txt' ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/spacejunk ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} '*' ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
