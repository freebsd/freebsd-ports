# New ports collection makefile for:   stream
# Date created:        10 May 2001
# Whom:        Scott Flatman <sf@dsinw.com>
#
# $FreeBSD$

PORTNAME=	stream
PORTVERSION=	1.0
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.cs.virginia.edu/pub/stream/Code/
DISTFILES=	second_cpu.c stream_d.c
DIST_SUBDIR=	stream-${PORTVERSION}

MAINTAINER=	sf@slappy.org
COMMENT=	Synthetic benchmark program that measures sustainable memory bandwidth

MAKEFILE=	${FILESDIR}/Makefile
PLIST_FILES=	bin/stream

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} -r ${_DISTDIR} ${WRKDIR}

post-install:
	${STRIP_CMD} ${PREFIX}/bin/stream

.include <bsd.port.mk>
