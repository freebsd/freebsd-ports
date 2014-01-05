# Created by: Scott Flatman <sf@dsinw.com>
# $FreeBSD$

PORTNAME=	stream
PORTVERSION=	5.10
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.cs.virginia.edu/stream/FTP/Code/
DISTFILES=	stream.c
DIST_SUBDIR=	${PORTNAME}-1.0/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Synthetic benchmark program that measures sustainable memory bandwidth

OPTIONS_DEFINE=	DOCS

NO_WRKSUBDIR=	yes

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	${WRKDIR}

PORTDOCS=	stream.c
PLIST_FILES=	bin/stream_bench

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o stream_bench stream.c -lm)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} stream_bench ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
