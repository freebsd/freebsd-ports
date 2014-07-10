# Created by: ijliao
# $FreeBSD$

PORTNAME=	libpeak
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/peak/${PORTNAME}/${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Parallel Events and Asynchronous tasKing Library

ONLY_FOR_ARCHS=	i386 amd64 sparc64

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

regression-test: build
	( \
	    cd ${WRKSRC}/tests; \
	    alltests=`ls *.c | sed -e 's|\.c||g'`; \
	    ${MAKE} $$alltests && ./test-suite.pl $$alltests \
	)

.include <bsd.port.mk>
