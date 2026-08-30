PORTNAME=	jsoncpp
DISTVERSION=	1.9.8
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	JSON reader and writer library for C++
WWW=		https://github.com/open-source-parsers/jsoncpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang cpe meson pkgconfig python:build,test
CPE_VENDOR=	jsoncpp_project
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	open-source-parsers

TEST_TARGET=	test

MESON_ARGS=	--default-library=both \
		--includedir include/jsoncpp

.include <bsd.port.mk>
