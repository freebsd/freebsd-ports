PORTNAME=	showkey
PORTVERSION=	1.7
CATEGORIES=	converters
MASTER_SITES=	http://catb.org/~esr/showkey/

MAINTAINER=	snkoppenaal@gmail.com
COMMENT=	Display cooked key sequences (keycap-to-keystrokes mappings)

LICENSE=	MIT

MAKE_ARGS=	CC="${CC} ${CFLAGS}"
ALL_TARGET=	showkey

PLIST_FILES=	bin/showkey man/man1/showkey.1.gz
PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/showkey ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/showkey.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
