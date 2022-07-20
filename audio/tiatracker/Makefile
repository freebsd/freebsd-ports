PORTNAME=	tiatracker
PORTVERSION=	1.3
DISTVERSIONSUFFIX=	.orig
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Music tracker for making Atari VCS 2600

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		compiler:c++11-lang dos2unix gl qmake qt:5 sdl tar:xz
DOS2UNIX_GLOB=	*.c *.cpp *.h *.k65 *.pro
USE_GL=		gl
USE_QT=		core gui widgets buildtools_build
USE_SDL=	sdl2

CFLAGS+=	`sdl2-config --cflags`
LDFLAGS+=	`sdl2-config --libs`

DESKTOP_ENTRIES=	"TIATracker" \
			"${COMMENT}" \
			"tt_icon" \
			"TIATracker" \
			"AudioVideo;AudioVideoEditing;" \
			false

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} \
		-e "s|\(TIATracker_manual.pdf\)|${DOCSDIR}/\1|" \
		-e "s|\(keymap.cfg\)|${ETCDIR}/\1|" \
		${WRKSRC}/mainwindow.cpp

do-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${DOCSDIR} \
		${STAGEDIR}${ETCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/TIATracker ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/data/keymap.cfg ${STAGEDIR}${ETCDIR}/keymap.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/songs/*.ttt ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/graphics/tt_icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/data/TIATracker_manual.pdf \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual/TIATracker_manual.odt \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual/Talk_Revision/TIATracker_Revision.odp \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
