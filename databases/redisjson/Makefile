PORTNAME=	redisjson
DISTVERSIONPREFIX=	v
DISTVERSION=	8.6.0
CATEGORIES=	databases

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	JSON data type for Redis
WWW=		https://oss.redislabs.com/redisjson/

LICENSE=	AGPLv3 RSALv2 SSPLv1
LICENSE_COMB=	dual
LICENSE_NAME_RSALv2=	Redis Source Available License v2
LICENSE_NAME_SSPLv1=	Server Side Public License v1
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS_RSALv2=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/libclang.so:devel/llvm${LLVM_DEFAULT}

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	RedisJSON
GH_PROJECT=	RedisJSON

PLIST_FILES=	lib/librejson.so

do-install:
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/*/librejson.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
