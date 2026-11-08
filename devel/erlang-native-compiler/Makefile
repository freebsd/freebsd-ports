PORTNAME=	erlang-native-compiler
PORTVERSION=	g20251024
CATEGORIES=	devel

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Native Code Compiler helper for Erlang
WWW=		https://github.com/davisp/erlang-native-compiler

LICENSE=	APACHE20

# must always be built against lowest BEAM version available in ports
# but can be run with any later version without issue
BUILD_DEPENDS=	erlang>22:lang/erlang

USE_GITHUB=	yes
GH_ACCOUNT=	davisp
GH_TAGNAME=	ba13cfb

MAKE_ENV=	PATH=${LOCALBASE}/lib/erlang/bin:${PATH}
NO_ARCH=	yes
PLIST_FILES=	bin/enc

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL} ${WRKSRC}/enc ${STAGEDIR}${PREFIX}/bin/enc

.include <bsd.port.mk>
