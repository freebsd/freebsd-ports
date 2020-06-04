# $FreeBSD$

PORTNAME=	re2
PORTVERSION=	1.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby bindings to re2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libgmp.so:math/gmp \
		libre2.so:devel/re2

USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
