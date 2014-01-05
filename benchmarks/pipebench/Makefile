# Created by: mich@freebsdcluster.org
# $FreeBSD$

PORTNAME=	pipebench
PORTVERSION=	0.40
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.habets.pp.se/pub/synscan/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Pipebench shows current throughput/amount of data through a pipe

PLIST_FILES=	bin/pipebench \
		man/man1/pipebench.1.gz

CFLAGS+=	-w -pedantic

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipebench ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pipebench.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
