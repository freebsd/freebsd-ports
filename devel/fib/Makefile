# New ports collection makefile for:	fib
# Date created:		8 August 2002
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	fib
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	http://resnet.uoregon.edu/~gurney_j/jmpc/dist/

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Fibonacci Heap Library

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN3=		fh_extractmin.3 fh_makeheap.3 fh_makekeyheap.3

post-install:
	${LN} -sf ${PREFIX}/lib/libfib.so.1 ${PREFIX}/lib/libfib.so
.for mf in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/${mf} ${PREFIX}/man/man3/
.endfor

.include <bsd.port.mk>
