# Created by: Stefan Eggers <seggers@semyam.dinoco.de>
# $FreeBSD$

PORTNAME=	crafty
PORTVERSION=	23.4
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

MAINTAINER=	ports@FreeBSD.org
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

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DOCFILES=	crafty.doc.ascii crafty.doc.ps
DISTFILES+=	${DOCFILES:S/$/:doc/}
UTILS=		bitmaps.tgz sound.zip
DISTFILES+=	${UTILS:S/$/:utils/}
.endif

.if ${ARCH} == "i386"
OPT+=		-DINLINE32
.elif ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.if defined(WITH_BOOK)
BOOKS+=		book.bin
DISTFILES+=	${BOOKS:S/$/:books/}
PKGNAMESUFFIX=	-open-default
CONFLICTS+=	crafty-open-enormous-* crafty-open-large-* crafty-open-medium-*
PLIST_SUB+=	BOOK=""
.else
PLIST_SUB+=	BOOK="@comment "
.endif

MAKE_ENV+=	opt="${OPT}" target=${OPSYS} CXFLAGS="${CXXFLAGS}"

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/start.pgn ${WRKSRC}/start.pgn
.if defined(WITH_BOOK)
	${CP} ${DISTDIR}/${DIST_SUBDIR}/book.bin ${WRKSRC}/book.bin
.endif
	${CP} ${DISTDIR}/${DIST_SUBDIR}/books.bin ${WRKSRC}/books.bin

post-build:
	(cd ${WRKSRC}; ./crafty bookpath=. <${FILESDIR}/books-building)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crafty ${STAGEDIR}${PREFIX}/bin/crafty
	${CHOWN} root:nogroup ${STAGEDIR}${PREFIX}/bin/crafty
	${CHMOD} 2555 ${STAGEDIR}${PREFIX}/bin/crafty
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/crafty/cpf
	${CHOWN} -R root:nogroup ${STAGEDIR}${PREFIX}/lib/crafty
	${CHMOD} 775 ${STAGEDIR}${PREFIX}/lib/crafty ${STAGEDIR}${PREFIX}/lib/crafty/cpf
.if defined(WITH_BOOK)
	${INSTALL_DATA} ${WRKSRC}/book.bin ${STAGEDIR}${PREFIX}/lib/crafty/book.bin
.endif
	${INSTALL_DATA} ${WRKSRC}/books.bin ${STAGEDIR}${PREFIX}/lib/crafty/books.bin
	${INSTALL_DATA} ${WRKSRC}/crafty.hlp ${STAGEDIR}${PREFIX}/lib/crafty/crafty.hlp
	${CHOWN} root:nogroup ${STAGEDIR}${PREFIX}/lib/crafty/book*
	${CHMOD} 664 ${STAGEDIR}${PREFIX}/lib/crafty/book*
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${DOCFILES} ${STAGEDIR}${DOCSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${UTILS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
