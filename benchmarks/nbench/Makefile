# Created by: Andrey Zakhvatov <andy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nbench
PORTVERSION=	2.2.3
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.tux.org/~mayer/linux/
DISTNAME=	${PORTNAME}-byte-${PORTVERSION}

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	BYTE Magazine's native benchmarks

ALL_TARGET=	# empty

PLIST_FILES=	bin/nbench share/nbench/NNET.DAT
PORTDOCS=	README README.submit RESULTS bdoc.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbench ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/NNET.DAT ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
