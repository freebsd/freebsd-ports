# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fib
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://resnet.uoregon.edu/~gurney_j/jmpc/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fibonacci Heap Library

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
ALL_TARGET=	libfib.a libfib.so.1
STATIC_INST=	libfib.a

MANPAGES=	fh_extractmin.3 fh_makeheap.3 fh_makekeyheap.3

.include <bsd.port.pre.mk>

.if defined(NO_PROFILE) || ${OPSYS} == DragonFly
PLIST_SUB+=	PROFILE="@comment "
.else
ALL_TARGET+=	libfib_p.a
STATIC_INST+=	libfib_p.a
PLIST_SUB+=	PROFILE=""
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/fib.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_LIB} ${WRKSRC}/libfib.so.1 ${STAGEDIR}${PREFIX}/lib/
	@(cd ${STAGEDIR}${PREFIX}/lib/; ${LN} -sf libfib.so.1 libfib.so)
	@(cd ${WRKSRC}; ${INSTALL_DATA} ${STATIC_INST} \
		${STAGEDIR}${PREFIX}/lib/)
	@(cd ${WRKSRC}; ${INSTALL_MAN} ${MANPAGES} \
		${STAGEDIR}${PREFIX}/man/man3/)

.include <bsd.port.post.mk>
