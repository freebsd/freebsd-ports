PORTNAME=	erlang-native-compiler
PORTVERSION=	g20210602
CATEGORIES=	devel

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Native Code Compiler helper for Erlang

LICENSE=	APACHE20

# must always be built against lowest BEAM version available in ports
# but can be run with any later version without issue
BUILD_DEPENDS=	erlang-runtime21>21:lang/erlang-runtime21

USE_GITHUB=	yes
GH_ACCOUNT=	davisp
GH_TAGNAME=	5761afb

MAKE_ENV=	PATH=${LOCALBASE}/lib/erlang21/bin:${PATH}
NO_ARCH=	yes
PLIST_FILES=	bin/enc

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL} ${WRKSRC}/enc ${STAGEDIR}${PREFIX}/bin/enc

.include <bsd.port.mk>
