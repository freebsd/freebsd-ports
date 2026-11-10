PORTNAME=	rapidyaml
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	devel

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Library to parse and emit YAML
WWW=		https://github.com/biojppm/rapidyaml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	git:devel/git@lite
LIB_DEPENDS=	libc4core.so:devel/c4core

USES=		compiler:c++11-lib cmake:noninja localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	biojppm
GH_PROJECT=	cmake:cmake
GH_SUBDIR=	ext/c4core/cmake:cmake
GH_TAGNAME=	469017f:cmake

USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_SUB=	VERSION=${DISTVERSION}

.include <bsd.port.mk>
