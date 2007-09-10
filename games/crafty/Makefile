# New ports collection makefile for:	crafty
# Date created:				31 May 1998
# Whom:					Stefan Eggers <seggers@semyam.dinoco.de>
#
# $FreeBSD$
#

PORTNAME=	crafty
PORTVERSION=	20.14
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cis.uab.edu/pub/hyatt/pgn/:data \
		ftp://ftp.cis.uab.edu/pub/hyatt/documentation/:doc \
		ftp://ftp.cis.uab.edu/pub/hyatt/source/:src
DISTFILES=	crafty-${PORTVERSION}.zip:src \
		start.pgn:data
DIST_SUBDIR=	crafty
EXTRACT_ONLY=	crafty-${PORTVERSION}.zip

MAINTAINER=	shoemaker@bluebottle.com
COMMENT=	A chess programm for playing and analyzing games

USE_ZIP=        yes
USE_GMAKE=	yes

.if !defined(NOPORTDOCS)
DOCFILES=	crafty.doc.ascii crafty.doc.ps
DISTFILES+=	${DOCFILES:S/$/:doc/}
.endif

ALL_TARGET=	freebsd

.if !defined(WITH_BOOKDIR)
WITH_BOOKDIR=	${PREFIX}/lib/crafty
.endif
.if !defined(WITH_LOGDIR)
WITH_LOGDIR=	/tmp
.endif
.if !defined(WITH_RCDIR)
WITH_RCDIR=	~/
.endif
.if !defined(WITH_TBDIR)
WITH_TBDIR=	${PREFIX}/lib/crafty/TB
.endif

OPT=		-DHASHSTATS -DTRACE -DBOOKDIR=\\\"${WITH_BOOKDIR}\\\" \
		-DLOGDIR=\\\"${WITH_LOGDIR}\\\" \
	       	-DRCDIR=\\\"${WITH_RCDIR}\\\" \
		-DTBDIR=\\\"${WITH_TBDIR}\\\"

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
OPT+=		-DINLINE32
# XXX Someone with ASM knowledge would have to fix the Sparc.S
.elif ${ARCH} == "sparc64"
OPT+=		-DINLINE32
CFLAGS+=	'$(CFLAGS) -D_REENTRANT -O3 -Wall \
		-fomit-frame-pointer -funroll-all-loops \
		-finline-functions -ffast-math' \
.else
OPT+=		-DFAST
.endif

MAKE_ENV+=	opt="${OPT}" target=${OPSYS} CXFLAGS="${CXXFLAGS}"

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/start.pgn ${WRKSRC}/start.pgn

post-build:
	(cd ${WRKSRC}; ./crafty bookpath=. <${FILESDIR}/books-building)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crafty ${PREFIX}/bin/crafty
	${CHOWN} nobody:nogroup ${PREFIX}/bin/crafty
	${CHMOD} 6555 ${PREFIX}/bin/crafty
	${MKDIR} ${PREFIX}/lib/crafty
	${CHOWN} nobody:nogroup ${PREFIX}/lib/crafty
	${INSTALL_DATA} ${WRKSRC}/books.bin ${PREFIX}/lib/crafty/books.bin
	${INSTALL_DATA} ${WRKSRC}/book.lrn ${PREFIX}/lib/crafty/book.lrn
	${INSTALL_DATA} ${WRKSRC}/position.bin ${PREFIX}/lib/crafty/position.bin
	${INSTALL_DATA} ${WRKSRC}/position.lrn ${PREFIX}/lib/crafty/position.lrn
	${TOUCH} ${PREFIX}/lib/crafty/book.bin
	${CHOWN} nobody:nogroup ${PREFIX}/lib/crafty/book*
	${CHOWN} nobody:nogroup ${PREFIX}/lib/crafty/position*
	${CHMOD} 664 ${PREFIX}/lib/crafty/book*
	${CHMOD} 664 ${PREFIX}/lib/crafty/position*
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
