PORTNAME=	bluemoon
DISTVERSION=	2.15
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/bluemoon/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Blue Moon card solitaire
WWW=		http://www.catb.org/~esr/bluemoon/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses:base

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/doc/${PORTNAME}/README \
		share/pixmaps/${PORTNAME}.png

do-build:
	cd ${WRKSRC} && \
		${CC} ${CFLAGS} -DRELEASE=\"${DISTVERSION}\" -I${NCURSESBASE}/include -L${NCURSESLIB} -lncurses -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.adoc ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>
