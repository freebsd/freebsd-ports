# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	dangerdeep
PORTVERSION=	0.3.0
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/danger_from_the_deep-src/${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source World War II German submarine simulation

LIB_DEPENDS=	libfftw3.so:math/fftw3
RUN_DEPENDS=	dangerdeep-data>0:games/dangerdeep-data

USES=		execinfo scons
USE_GL=		yes
USE_SDL=	sdl mixer image net

MAKE_ARGS=	installbindir=${PREFIX}/bin installdatadir=${DATADIR}
MAKE_ENV=	X11BASE=${LOCALBASE}

PLIST_FILES=	bin/dangerdeep bin/crosssection bin/damagemodel \
		bin/oceantest bin/portal bin/viewmodel \
		man/man6/dangerdeep.6.gz

PORTDOCS=	CREDITS README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING)
MAKE_ARGS+=	usex86sse=-1	# disable MMX/SSE on the build cluster
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/games/dangerdeep|${DATADIR}|; \
		s|Linux|"Danger from the Deep"|' ${WRKSRC}/doc/man/dangerdeep.6
	@${REINPLACE_CMD} -e 's|/usr/X11BASE|${LOCALBASE}|g' \
	    ${WRKSRC}/SConstruct

do-install:
	@cd ${WRKSRC}/build/freebsd && \
		${INSTALL_PROGRAM} dangerdeep crosssection damagemodel oceantest \
			portal viewmodel ${STAGEDIR}${PREFIX}/bin

	${INSTALL_MAN} ${WRKSRC}/doc/man/dangerdeep.6 ${STAGEDIR}${PREFIX}/man/man6
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/man/man6/dangerdeep.6
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
