# Created by: Johan Str??m <johan@stromnet.se>
# $FreeBSD$

PORTNAME=	jsoncpp
PORTVERSION=	1.9.4
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	JSON reader and writer library for C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang meson pkgconfig python:3.6+,build,test
USE_GITHUB=	yes
GH_ACCOUNT=	open-source-parsers
MESON_ARGS=	--default-library=both
USE_LDCONFIG=	yes

TEST_TARGET=	test

.include <bsd.port.mk>
