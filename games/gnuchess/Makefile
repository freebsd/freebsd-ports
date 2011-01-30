# New ports collection makefile for:	Gnu Chess
# Date created:		04 July 1996
# Whom:			markm
#
# $FreeBSD$
#

PORTNAME=	gnuchess
PORTVERSION=	5.08
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	chess
# The DISTFILES here is explicitly needed because it can be extended later.
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	"Classic" Gnu Chess

PLIST_FILES=	bin/gnuchess \
		bin/gnuchessx

PORTDOCS=	*

OPTIONS=    OPENING_BOOK "Install opening book (25 MB download)" on

.include <bsd.port.pre.mk>

.if defined(WITH_OPENING_BOOK)
DISTFILES+=	book_1.01.pgn.gz
PLIST_DIRS+=	%%DATADIR%%
PLIST_FILES+=	%%DATADIR%%/book.dat
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}" MKDIR_P="${MKDIR}"

post-patch:
	@${REINPLACE_CMD} -e 's|-D_THREAD_SAFE|${PTHREAD_CFLAGS:S/"//g}|g ; \
		 s|-pthread ||g' ${WRKSRC}/configure

pre-install:
.if defined(WITH_OPENING_BOOK)
	@${SH} ${SCRIPTDIR}/create_opening_book.sh ${DISTDIR} ${WRKSRC}
.endif

post-install:
	${LN} -f ${PREFIX}/bin/gnuchess ${PREFIX}/bin/gnuchessx
.if defined(WITH_OPENING_BOOK)
	@${ECHO_CMD} Installing opening book
	${MKDIR} ${DATADIR} && \
	${CP} ${WRKSRC}/src/book.dat ${DATADIR}
.endif
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} Installing documentation
	${MKDIR} ${DOCSDIR} && \
	${CP} ${WRKSRC}/NEWS ${DOCSDIR} && \
	${CP} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
