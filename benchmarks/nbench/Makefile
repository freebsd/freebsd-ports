# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	nbench
PORTVERSION=	2.2.3
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.tux.org/~mayer/linux/
DISTNAME=	${PORTNAME}-byte-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BYTE Magazine's native benchmarks

ALL_TARGET=	# empty
MAKE_JOBS_UNSAFE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbench ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/NNET.DAT ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in README README.submit RESULTS bdoc.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
