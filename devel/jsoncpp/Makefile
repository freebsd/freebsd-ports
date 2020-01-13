# Created by: Johan Str??m <johan@stromnet.se>
# $FreeBSD$

PORTNAME=	jsoncpp
PORTVERSION=	1.9.2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	JSON reader and writer library for C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	open-source-parsers
MESON_ARGS=	--default-library=both
USE_LDCONFIG=	yes

.include <bsd.port.mk>
