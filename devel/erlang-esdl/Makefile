PORTNAME=	esdl
DISTVERSIONPREFIX=	esdl-
DISTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Library for accessing SDL and OpenGL through Erlang

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.terms

BUILD_DEPENDS=	erl:lang/erlang
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		erlang:rebar gl sdl
USE_GITHUB=	yes
GH_ACCOUNT=	dgud

USE_GL=		gl glu
USE_SDL=	sdl image ttf

PLIST_SUB=	VERSION="${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} "s/\(vsn,\) git/\1 \"${DISTVERSION}\"/" "${WRKSRC}/src/sdl.app.src"

post-install:
	@${LN} -sf ${PORTNAME}-${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}

.include <bsd.port.mk>
