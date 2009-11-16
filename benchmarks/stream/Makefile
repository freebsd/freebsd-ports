# New ports collection makefile for:   stream
# Date created:        10 May 2001
# Whom:        Scott Flatman <sf@dsinw.com>
#
# $FreeBSD$

PORTNAME=	stream
PORTVERSION=	5.9
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.cs.virginia.edu/stream/FTP/Code/
DISTFILES=	stream.c
DIST_SUBDIR=	${PORTNAME}-1.0/${PORTVERSION}

MAINTAINER=	shuvaev@physik.uni-wuerzburg.de
COMMENT=	Synthetic benchmark program that measures sustainable memory bandwidth

PLIST_FILES=	bin/stream_bench
PORTDOCS=	stream.c

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${_DISTDIR}/stream.c ${WRKSRC}

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -o stream_bench stream.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stream_bench ${PREFIX}/bin
.	if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.	endif

.include <bsd.port.mk>
