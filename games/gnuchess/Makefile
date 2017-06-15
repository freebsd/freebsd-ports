# Created by: markm
# $FreeBSD$

PORTNAME=	gnuchess
PORTVERSION=	6.2.4
CATEGORIES=	games
MASTER_SITES=	GNU/chess
# The DISTFILES here is explicitly needed because it can be extended later.
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	"Classic" Gnu Chess

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MKDIR_P="${MKDIR}"
INFO=		gnuchess
USES=		cpe shebangfix
SHEBANG_FILES=	doc/quotes.rb
CPE_PRODUCT=	chess
CPE_VENDOR=	gnu

OPTIONS_DEFINE=		OPENING_BOOK DOCS NLS
OPTIONS_DEFAULT=	OPENING_BOOK
OPTIONS_SUB=		yes
OPENING_BOOK_DESC=	Install opening book (25 MB download)
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENING_BOOK}
DISTFILES+=	book_1.02.pgn.gz
EXTRACT_ONLY+=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
.endif

post-build:
.if ${PORT_OPTIONS:MOPENING_BOOK}
	zcat ${DISTDIR}/book_1.02.pgn.gz > ${WRKSRC}/src/book.pgn
	cd ${WRKSRC}/src && ${PRINTF} "book add book.pgn\nquit\n" | ./gnuchess
	@${REINPLACE_CMD} -e '/Book =/s/false/true/' ${WRKSRC}/src/gnuchess.ini
.endif

post-install:
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -f gnuchess gnuchessx
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
