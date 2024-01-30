PORTNAME=	gnuchess
PORTVERSION=	6.2.9
PORTREVISION=	1
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
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	MKDIR_P="${MKDIR}"

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
	cd ${WRKSRC}/src && ( ${ECHO} book add book.pgn; sleep 1; ${ECHO} quit ) | ./gnuchess
	@${REINPLACE_CMD} -e '/Book =/s/false/true/' ${WRKSRC}/src/gnuchess.ini

post-install:
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -f gnuchess gnuchessx

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
	${RM} ${STAGEDIR}${DOCSDIR}/gnuchess.info

.include <bsd.port.mk>
