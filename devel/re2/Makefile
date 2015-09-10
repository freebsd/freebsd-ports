# Created by: Julien Laffaye <kimelto@gmail.com>
# $FreeBSD$

PORTNAME=	re2
PORTVERSION=	20150601
CATEGORIES=	devel

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Fast C++ regex library

LICENSE=	BSD3CLAUSE

MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" prefix=${PREFIX}
USE_LDCONFIG=	yes
USES=		compiler:c++11-lang gmake pathfix

GH_ACCOUNT=	google
GH_TAGNAME=	${PORTVERSION:C|(....)(..)(..)|\1-\2-\3|}
USE_GITHUB=	yes

post-build:
	@${STRIP_CMD} ${WRKSRC}/obj/so/libre2.so

.include <bsd.port.mk>
