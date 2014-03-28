# Created by: Stefan Eggers <seggers@semyam.dinoco.de>
# $FreeBSD$

PORTNAME=	crafty
PORTVERSION=	23.8
CATEGORIES=	games
MASTER_SITES=	http://www.craftychess.com/:src \
		http://www.cis.uab.edu/hyatt/crafty/pgn/:data \
		http://www.cis.uab.edu/hyatt/crafty/documentation/:doc \
		http://www.cis.uab.edu/hyatt/crafty/source/:src \
		http://www.cis.uab.edu/hyatt/crafty/book/:utils \
		http://www.cis.uab.edu/hyatt/crafty/book/:books
DISTFILES=	crafty-${PORTVERSION}.zip:src \
		start.pgn:data
DIST_SUBDIR=	crafty
EXTRACT_ONLY=	crafty-${PORTVERSION}.zip

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Chess program for playing and analyzing games

USES=		gmake zip

BOOKS=		books.bin
DISTFILES+=	${BOOKS:S/$/:books/}

ALL_TARGET=	freebsd

WITH_BOOKDIR?=	${PREFIX}/lib/crafty
WITH_LOGDIR?=	/tmp
WITH_RCDIR?=	~/
WITH_TBDIR?=	${PREFIX}/lib/crafty/TB
WITH_PERSDIR?=	${PREFIX}/lib/crafty/cpf

OPT=		-DCPUS=4 -DHASHSTATS -DTRACE -DBOOKDIR=\\\"${WITH_BOOKDIR}\\\" \
		-DLOGDIR=\\\"${WITH_LOGDIR}\\\" \
		-DRCDIR=\\\"${WITH_RCDIR}\\\" \
		-DTBDIR=\\\"${WITH_TBDIR}\\\" \
		-DPERSDIR=\\\"${WITH_PERSDIR}\\\" -DSKILL

OPTIONS_DEFINE=	DOCS BOOK
OPTIONS_DEFAULT=DOCS
OPTIONS_SUB=	yes
BOOK_DESC=	Include (default) opening book

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
OPT+=		-DINLINE32
.elif ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DOCFILES=	crafty.doc.ascii crafty.doc.ps
DISTFILES+=	${DOCFILES:S/$/:doc/}
UTILS=		bitmaps.tgz sound.zip
DISTFILES+=	${UTILS:S/$/:utils/}
.endif

.if ${PORT_OPTIONS:MBOOK}
BOOKS+=		book.bin
DISTFILES+=	${BOOKS:S/$/:books/}
PKGNAMESUFFIX=	-open-default
CONFLICTS+=	crafty-open-enormous-* crafty-open-large-* crafty-open-medium-*
.endif

MAKE_ENV+=	opt="${OPT}" target=${OPSYS} CXFLAGS="${CXXFLAGS}"

post-extract:
	cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} start.pgn books.bin ${WRKSRC}
.if ${PORT_OPTIONS:MBOOK}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/book.bin ${WRKSRC}
.endif

post-build:
	(cd ${WRKSRC}; ./crafty bookpath=. <${FILESDIR}/books-building)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crafty ${STAGEDIR}${PREFIX}/bin/crafty
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/crafty/cpf
.if ${PORT_OPTIONS:MBOOK}
	${INSTALL_DATA} ${WRKSRC}/book.bin ${STAGEDIR}${PREFIX}/lib/crafty
.endif
	${INSTALL_DATA} ${WRKSRC}/books.bin ${WRKSRC}/crafty.hlp \
		${STAGEDIR}${PREFIX}/lib/crafty
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${DOCFILES} ${UTILS} \
		${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
