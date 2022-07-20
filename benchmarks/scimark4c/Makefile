PORTNAME=	scimark4c
PORTVERSION=	4
CATEGORIES=	benchmarks
MASTER_SITES=	http://math.nist.gov/scimark2/
DISTNAME=	${PORTNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	ANSI C version of the SciMark2 benchmark

LICENSE=	PD

USES=		zip

WRKSRC=		${WRKDIR}/${PORTNAME:C/4c/4/}
PLIST_FILES=	bin/scimark4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scimark4 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
