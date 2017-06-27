# Created by: ijliao
# $FreeBSD$

PORTNAME=	libpeak
PORTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/peak/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parallel Events and Asynchronous tasKing Library

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=		amd64 i386 sparc64

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

regression-test: build
	( \
	    cd ${WRKSRC}/tests; \
	    alltests=`ls *.c | sed -e 's|\.c||g'`; \
	    ${MAKE} $$alltests && ./test-suite.pl $$alltests \
	)

.include <bsd.port.mk>
