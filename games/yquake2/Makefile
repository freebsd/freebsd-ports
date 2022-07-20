PORTNAME=	yquake2
PORTVERSION=	8.01
CATEGORIES=	games
MASTER_SITES=	https://deponie.yamagi.org/quake2/
DISTNAME=	quake2-${PORTVERSION}

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Improved version of Icculus Quake II

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

# Quake II loads optional libraries via dlopen(3)
BUILD_DEPENDS=	${LOCALBASE}/include/curl/curl.h:ftp/curl
RUN_DEPENDS=	${LOCALBASE}/lib/libcurl.so:ftp/curl

USES=		gmake openal gl sdl tar:xz
USE_GL=		gl
USE_SDL=	sdl2
MAKE_ARGS=	VERBOSE=1 WITH_SYSTEMWIDE=yes \
		WITH_SYSTEMDATADIR="${Q2DIR}" \
		WITH_SYSTEMLIBDIR="${PREFIX}/lib/${PORTNAME}"

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/q2ded \
		${STAGEDIR}${PREFIX}/bin/yq2ded
	${INSTALL_PROGRAM} ${WRKSRC}/release/quake2 \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/baseq2
	${INSTALL_LIB} ${WRKSRC}/release/baseq2/game.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/baseq2
	${INSTALL_LIB} ${WRKSRC}/release/ref_*.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${WRKSRC}/doc/*.md \
		${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.mk>
