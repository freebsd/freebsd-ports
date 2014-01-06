# Created by: mharo@FreeBSD.org
# $FreeBSD$

PORTNAME=	ttcp
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	benchmarks net
MASTER_SITES=	ftp://ftp.sgi.com/sgi/src/ttcp/
DISTFILES=	ttcp.c ttcp.1 README
EXTRACT_ONLY=	#none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Benchmarking tool for analysing TCP and UDP performance

LICENSE=	PUBLIC_DOMAIN
LICENSE_NAME=	${LICENSE:S/_/ /}
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_TEXT=	The license: ${_LICENSE} (${_LICENSE_NAME}) is standard, please read from the web.


NO_WRKSUBDIR=	yes
DIST_SUBDIR=	${PORTNAME}

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/ttcp.c ${WRKSRC}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/ttcp.1 ${WRKSRC}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/README ${WRKSRC}

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/ttcp ${WRKSRC}/ttcp.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttcp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ttcp.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
