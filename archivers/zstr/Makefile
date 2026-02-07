PORTNAME=	zstr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	archivers devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only ZLib wrapper
WWW=		https://github.com/mateidavid/zstr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	mateidavid

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/strict_fstream.hpp \
		include/zstr.hpp

do-install:
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
