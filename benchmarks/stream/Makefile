# New ports collection makefile for:   stream
# Date created:        10 May 2001
# Whom:        Scott Flatman <sf@dsinw.com>
#
# $FreeBSD$

PORTNAME=	stream
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.cs.virginia.edu/pub/stream/Code/
DISTFILES=	stream.c README
DIST_SUBDIR=	stream-${PORTVERSION}

MAINTAINER=	sf@slappy.org
COMMENT=	Synthetic benchmark program that measures sustainable memory bandwidth

PLIST_FILES=	bin/stream
PORTDOCS=	stream.c README

do-extract:
	@${MKDIR} ${BUILD_WRKSRC}
	@${CP} ${_DISTDIR}/stream.c ${BUILD_WRKSRC}

do-build:
	(cd ${BUILD_WRKSRC} ; ${CC} ${CFLAGS} -o stream stream.c -lm)

do-install:
	(cd ${BUILD_WRKSRC}; ${INSTALL_PROGRAM} stream ${PREFIX}/bin)
.	if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		(cd ${_DISTDIR}; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.	endif

.include <bsd.port.mk>
