# New ports collection makefile for:	sdb
# Date created:				08 Sep 2005
# Whom:					Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	sdb
PORTVERSION=	1.0.2
CATEGORIES=	games
MASTER_SITES=	http://gcsociety.pc.cc.cmu.edu/~frenzy/

MAINTAINER=	amdmi3@mail.ru
COMMENT=	Futuristic overhead shooter

USE_X_PREFIX=	yes
USE_SDL=	mixer image sdl
USE_GL=		yes
USE_GMAKE=	yes
USE_GCC=	3.4+

BUILD_WRKSRC=	${WRKSRC}/src

CPPFLAGS=	`${SDL_CONFIG} --cflags` -I${X11BASE}/include
LDFLAGS=	`${SDL_CONFIG} --libs` -L${X11BASE}/lib -lSDL_image -lSDL_mixer -lGL -lGLU
MAKE_ARGS=	CPP="${CXX}" CXXFLAGS="${CXXFLAGS} ${CPPFLAGS}" LIBS="${LDFLAGS}"

PLIST_FILES=	bin/sdb
PLIST_DIRS=	%%DATADIR%%
PORTDOCS=	README

PLIST=		${WRKDIR}/pkg-plist
DATADIRS=	levels models snd sprites

post-patch:
	@${REINPLACE_CMD} -e 's|<SDL/|<|' ${WRKSRC}/src/sdb.h
	@${REINPLACE_CMD} -Ee 's,(levels|models|snd|sprites)/,${DATADIR}/&,g' \
		${WRKSRC}/src/sdb.h ${WRKSRC}/src/game.cpp

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} ${DATADIRS} ! -type d | ${SORT} \
		| ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
	${FIND} ${DATADIRS} -type d ! -empty | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sdb ${PREFIX}/bin
	cd ${WRKSRC} && \
	${FIND} ${DATADIRS} -type d ! -empty -exec \
		${MKDIR} "${DATADIR}/{}" \; && \
	${FIND} ${DATADIRS} ! -type d -exec \
		${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
