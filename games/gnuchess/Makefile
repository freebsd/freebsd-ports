# New ports collection makefile for:	Gnu Chess
# Date created:		04 July 1996
# Whom:			markm
#
# $FreeBSD$
#

PORTNAME=	gnuchess
PORTVERSION=	6.0.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	chess
# The DISTFILES here is explicitly needed because it can be extended later.
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	"Classic" Gnu Chess

INFO=		gnuchess
PLIST_FILES=	bin/gnuchess bin/gnuchessu bin/gnuchessx
PORTDOCS=	*
PORTDATA=	*

OPTIONS=	OPENING_BOOK "Install opening book (25 MB download)" On

.include <bsd.port.pre.mk>

.if defined(WITH_OPENING_BOOK)
DISTFILES+=	book_1.02.pgn.gz
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
USE_PERL5_BUILD=yes
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}" MKDIR_P="${MKDIR}"

post-patch:
	@${REINPLACE_CMD} -e 's|-D_THREAD_SAFE|${PTHREAD_CFLAGS:S/"//g}|g ; \
		 s|-pthread ||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/BookFile = fopen/{p;s/B.*/if (BookFile == NULL)\
			BookFile = fopen(full_file_name,"rb");/;}' \
		${WRKSRC}/src/adapter/book.cpp

post-build:
.if defined(WITH_OPENING_BOOK)
	zcat ${DISTDIR}/book_1.02.pgn.gz > ${WRKSRC}/src/book.pgn
	cd ${WRKSRC}/src && ${PERL} ${SCRIPTDIR}/create_opening_book.pl
	@${REINPLACE_CMD} -e '/Book =/s/false/true/' ${WRKSRC}/src/gnuchess.ini
.endif

post-install:
	${LN} -f ${PREFIX}/bin/gnuchess ${PREFIX}/bin/gnuchessx
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
