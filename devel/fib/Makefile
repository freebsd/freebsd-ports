# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fib
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	http://resnet.uoregon.edu/~gurney_j/jmpc/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fibonacci Heap Library

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MANPAGES=	fh_extractmin.3 fh_makeheap.3 fh_makekeyheap.3

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfib.so.1
	@(cd ${STAGEDIR}${PREFIX}/lib/; ${LN} -sf libfib.so.1 libfib.so)
.for mf in ${MANPAGES}
	${INSTALL_MAN} ${WRKSRC}/${mf} ${STAGEDIR}${PREFIX}/man/man3/
.endfor

.include <bsd.port.mk>
