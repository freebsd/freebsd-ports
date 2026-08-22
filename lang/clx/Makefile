PORTNAME=	clx
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	lang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Ahead-of-time Lua compiler producing native executables
WWW=		https://github.com/samyeyo/clx

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++20-lang

USE_GITHUB=	yes
GH_ACCOUNT=	samyeyo

PLIST_FILES=	bin/clx \
		include/clx.h \
		include/clx_runtime.h \
		include/clx_simd.h \
		lib/libclx.a \
		lib/libclx_lua.a \
		lib/libclx_size.a

.include <bsd.port.mk>
