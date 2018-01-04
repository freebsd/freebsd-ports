# $FreeBSD$

PORTNAME=	rice
PORTVERSION=	2.1.2
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	C++ interface to Rubys C API

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	fails to configure: could not find ruby.h

USE_RUBY=	yes
USES=		autoreconf:build gem

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/test/unittest

.include <bsd.port.mk>
