PORTNAME=	bluemoon
DISTVERSION=	2.13
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/bluemoon/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Blue Moon card solitaire
WWW=		http://www.catb.org/~esr/bluemoon/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/man/man6/${PORTNAME}.6.gz \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	NEWS.adoc README
OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} && \
		${CC} ${CFLAGS} -DRELEASE=\"${DISTVERSION}\" -I${NCURSESINC} -L${NCURSESLIB} -lncurses -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${STAGEDIR}${PREFIX}/share/man/man6/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
