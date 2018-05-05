# Created by: jkoshy
# $FreeBSD$

PORTNAME=	NetPIPE
PORTVERSION=	3.7.2
CATEGORIES=	benchmarks net
MASTER_SITES=	http://bitspjoule.org/netpipe/code/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Self-scaling network benchmark

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-06-06

# The default port builds and installs only the TCP version of
# netpipe(1).  The sources support many other variants.

PORTDOCS=	README netpipe_paper.ps
PLIST_FILES=	bin/NPtcp bin/NPtcp6 man/man1/netpipe.1.gz

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:tl}

do-build:
	cd ${WRKSRC} \
		&& ${CC} ${CFLAGS} src/netpipe.c src/tcp.c -DTCP -o NPtcp \
		&& ${CC} ${CFLAGS} src/netpipe.c src/tcp6.c -DTCP6 -o NPtcp6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/NPtcp ${STAGEDIR}${PREFIX}/bin/NPtcp
	${INSTALL_PROGRAM} ${WRKSRC}/NPtcp6 ${STAGEDIR}${PREFIX}/bin/NPtcp6
	${INSTALL_MAN} ${WRKSRC}/dox/netpipe.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.for doc in ${PORTDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dox/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
