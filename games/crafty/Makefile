# New ports collection makefile for:	crafty
# Date created:				31 May 1998
# Whom:					Stefan Eggers <seggers@semyam.dinoco.de>
#
# $FreeBSD$
#

PORTNAME=	crafty
PORTVERSION=	18.9
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cis.uab.edu/pub/hyatt/ \
		ftp://ftp.cis.uab.edu/pub/hyatt/common/ \
		ftp://ftp.cis.uab.edu/pub/hyatt/v18/ \
		ftp://ftp.jpunix.com/pub/hyatt/ \
		ftp://ftp.jpunix.com/pub/hyatt/common/ \
		ftp://ftp.jpunix.com/pub/hyatt/v18/
DISTFILES=	crafty-${PORTVERSION}.tar.gz crafty.doc crafty.faq read.me start.zip

MAINTAINER=	seggers@semyam.dinoco.de

.if ${MACHINE_ARCH} == "i386"
ALL_TARGET=	freebsd-i386
.else
ALL_TARGET=	freebsd-generic
.endif
DIST_SUBDIR=	crafty
EXTRACT_ONLY=	crafty-${PORTVERSION}.tar.gz
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
