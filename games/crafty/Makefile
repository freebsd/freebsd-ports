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

.if !defined(NOPORTDOCS)
DOCFILES=	crafty.doc.ascii crafty.doc.ps
DISTFILES+=	${DOCFILES:S/$/:doc/}
UTILS=		bitmaps.tgz sound.zip
DISTFILES+=	${UTILS:S/$/:utils/}
.endif

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

NO_STAGE=	yes
.include <bsd.port.pre.mk>

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
	${INSTALL_PROGRAM} ${WRKSRC}/crafty ${PREFIX}/bin/crafty
	${CHOWN} root:nogroup ${PREFIX}/bin/crafty
	${CHMOD} 2555 ${PREFIX}/bin/crafty
	${MKDIR} ${PREFIX}/lib/crafty/cpf
	${CHOWN} -R root:nogroup ${PREFIX}/lib/crafty
	${CHMOD} 775 ${PREFIX}/lib/crafty ${PREFIX}/lib/crafty/cpf
.if defined(WITH_BOOK)
	${INSTALL_DATA} ${WRKSRC}/book.bin ${PREFIX}/lib/crafty/book.bin
.endif
	${INSTALL_DATA} ${WRKSRC}/books.bin ${PREFIX}/lib/crafty/books.bin
	${INSTALL_DATA} ${WRKSRC}/crafty.hlp ${PREFIX}/lib/crafty/crafty.hlp
	${CHOWN} root:nogroup ${PREFIX}/lib/crafty/book*
	${CHMOD} 664 ${PREFIX}/lib/crafty/book*
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${UTILS} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
