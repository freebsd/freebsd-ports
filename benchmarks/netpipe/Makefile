# New ports collection makefile for: netpipe
# Date created:		20 Feb 1998
# Whom:			jkoshy
#
# $FreeBSD$

PORTNAME=	NetPIPE
PORTVERSION=	3.7.1
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.scl.ameslab.gov/Projects/Netpipe/code/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	A self-scaling network benchmark

# The default port builds and installs only the TCP version of
# netpipe(1).  The sources support many other variants.

MAN1=		netpipe.1
PORTDOCS=	README netpipe_paper.ps
PLIST_FILES=	bin/NPtcp bin/NPtcp6

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:L}

do-build:
	cd ${WRKSRC} \
		&& ${CC} ${CFLAGS} src/netpipe.c src/tcp.c -DTCP -o NPtcp \
		&& ${CC} ${CFLAGS} src/netpipe.c src/tcp6.c -DTCP6 -o NPtcp6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/NPtcp ${PREFIX}/bin/NPtcp
	${INSTALL_PROGRAM} ${WRKSRC}/NPtcp6 ${PREFIX}/bin/NPtcp6
	${INSTALL_MAN} ${WRKSRC}/dox/netpipe.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
.for doc in ${PORTDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dox/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
