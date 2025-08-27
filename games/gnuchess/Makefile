PORTNAME=	gnuchess
DISTVERSION=	6.3.0
CATEGORIES=	games
MASTER_SITES=	GNU/chess
# The DISTFILES here is explicitly needed because it can be extended later.
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Classic Gnu Chess
WWW=		https://savannah.gnu.org/projects/chess

LICENSE=	GPLv3+

USES=		cpe shebangfix
CPE_VENDOR=	gnu
CPE_PRODUCT=	chess
USE_CXXSTD=	c++14

SHEBANG_FILES=	doc/quotes.rb

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MKDIR_P="${MKDIR}"

LDFLAGS+=		-lpthread

INFO=		gnuchess

OPTIONS_DEFINE=		OPENING_BOOK DOCS NLS
OPTIONS_DEFAULT=	OPENING_BOOK
OPTIONS_SUB=		yes

OPENING_BOOK_DESC=	Install opening book (25 MB download)

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
OPENING_BOOK_DISTFILES=	book_1.02.pgn.gz
OPENING_BOOK_EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

post-build-OPENING_BOOK-on:
	zcat ${DISTDIR}/book_1.02.pgn.gz > ${WRKSRC}/src/book.pgn
	cd ${WRKSRC}/src && ( ${ECHO} book add book.pgn; sleep 1; ${ECHO} quit )
	@${REINPLACE_CMD} -e '/Book =/s/false/true/' ${WRKSRC}/doc/gnuchess.ini.in

post-install:
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -f gnuchess gnuchessx

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
	${RM} ${STAGEDIR}${DOCSDIR}/gnuchess.info
	${RM} ${STAGEDIR}${DOCSDIR}/gnuchess.ini.in
	${RM} ${STAGEDIR}${DOCSDIR}/pkg.texi.in

.include <bsd.port.mk>
