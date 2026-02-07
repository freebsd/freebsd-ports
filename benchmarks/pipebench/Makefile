PORTNAME=	pipebench
PORTVERSION=	0.40
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.habets.pp.se/synscan/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pipebench shows current throughput/amount of data through a pipe
WWW=		https://www.habets.pp.se/synscan/programs.php?prog=pipebench

PLIST_FILES=	bin/pipebench \
		share/man/man1/pipebench.1.gz

CFLAGS+=	-w -pedantic

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipebench ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pipebench.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
