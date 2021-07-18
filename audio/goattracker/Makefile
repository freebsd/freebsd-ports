# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	goattracker
PORTVERSION=	2.76
CATEGORIES=	audio
MASTER_SITES=	SF/goattracker2/GoatTracker%202/${PORTVERSION} \
		LOCAL/ehaupt
DISTNAME=	GoatTracker_${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Crossplatform music editor for creating Commodore 64 music

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/copying

USES=		dos2unix gmake sdl zip
USE_SDL=	sdl

MAKEFILE=	makefile

DESKTOP_ENTRIES=	"GoatTracker 2" \
			"${COMMENT}" \
			"${PREFIX}/share/pixmaps/goattrk2.ico" \
			"goattrk2" \
			"" \
			false

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	@${FIND} ${WRKSRC} -name '*.o' -type f -exec ${RM} -f {} \+

do-build:
	@cd ${WRKSRC}/src/bme; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS}
	@cd ${WRKSRC}/src; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS}

do-install:
.for f in goattrk2 gt2reloc ins2snd2 mod2sng sngspli2
	${INSTALL_PROGRAM} ${WRKSRC}/linux/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/src/goattrk2.ico ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.sng ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
