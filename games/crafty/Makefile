# New ports collection makefile for:	crafty
# Version required:			17.3
# Date created:				31 May 1998
# Whom:					Stefan Eggers <seggers@semyam.dinoco.de>
#
# $FreeBSD$
#

DISTNAME=	crafty-17.3
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cis.uab.edu/pub/hyatt/ \
		ftp://ftp.cis.uab.edu/pub/hyatt/common/ \
		ftp://ftp.cis.uab.edu/pub/hyatt/v17/ \
		ftp://ftp.jpunix.com/pub/hyatt/ \
		ftp://ftp.jpunix.com/pub/hyatt/common/ \
		ftp://ftp.jpunix.com/pub/hyatt/v17/
DISTFILES=	crafty-17.3.tar.gz crafty.doc crafty.faq read.me start.zip

MAINTAINER=	seggers@semyam.dinoco.de

ALL_TARGET=	crafty
DIST_SUBDIR=	crafty
EXTRACT_ONLY=	crafty-17.3.tar.gz
IGNOREFILES=	crafty.doc crafty.faq read.me

MAN6=		crafty.6
NO_WRKSUBDIR=	yes

post-extract:
	(cd ${WRKDIR}; ${GUNZIP_CMD} <${DISTDIR}/${DIST_SUBDIR}/start.zip >${WRKDIR}/start.pgn)

post-build:
	(cd ${WRKDIR}; ./crafty <${FILESDIR}/books-building)

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/crafty ${PREFIX}/bin/crafty
	${MKDIR} ${PREFIX}/lib/crafty
	${INSTALL_DATA} ${WRKDIR}/books.bin ${PREFIX}/lib/crafty/books.bin
	${INSTALL_MAN} ${FILESDIR}/crafty.6 ${MANPREFIX}/man/man6/crafty.6
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/crafty
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/crafty.doc ${PREFIX}/share/doc/crafty/crafty.doc
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/crafty.faq ${PREFIX}/share/doc/crafty/crafty.faq
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/read.me ${PREFIX}/share/doc/crafty/read.me
.endif

post-install:
	strip ${PREFIX}/bin/crafty

.include <bsd.port.mk>
