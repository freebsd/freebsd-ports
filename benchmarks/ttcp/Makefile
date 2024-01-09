PORTNAME=	ttcp
PORTVERSION=	1.12
PORTREVISION=	3
CATEGORIES=	benchmarks net
MASTER_SITES=	https://BSDforge.com/projects/source/benchmarks/ttcp/
DISTFILES=	ttcp.c ttcp.1 README
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Benchmarking tool for analysing TCP and UDP performance
WWW=		https://ftp.arl.army.mil/~mike/ttcp.html

LICENSE=	PD

BROKEN=		Unfetchable
DEPRECATED=     Abandonware, no release in over 20 years. Consider using benchmarks/iperf3 or benchmarks/nttcp
EXPIRATION_DATE=2024-02-29

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DOCS

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/ttcp.c ${WRKSRC}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/ttcp.1 ${WRKSRC}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/README ${WRKSRC}

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/ttcp ${WRKSRC}/ttcp.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttcp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ttcp.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
