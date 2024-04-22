PORTNAME=	sl
PORTVERSION=	5.02
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	hym@cocoa.freemail.ne.jp
COMMENT=	Steam locomotive runs across the screen if you type "sl"
WWW=		https://www.tkl.iis.u-tokyo.ac.jp/~toyoda/index_e.html

LICENSE=	SL_CUSTOM
LICENSE_NAME=	sl Program License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	mtoyoda

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		share/man/ja/man1/${PORTNAME}.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-build:
	${CC} ${CFLAGS} -I${WRKSRC} -o ${WRKSRC}/sl ${WRKSRC}/sl.c \
		${LDFLAGS} -lncurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/ja/man1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1.ja ${STAGEDIR}${PREFIX}/share/man/ja/man1/${PORTNAME}.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in README.md README.ja.md LICENSE
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
