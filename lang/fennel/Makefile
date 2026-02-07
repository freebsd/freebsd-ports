PORTNAME=	fennel
DISTVERSION=	1.6.0
CATEGORIES=	lang
MASTER_SITES=	https://git.sr.ht/~technomancy/${PORTNAME}/archive/${DISTVERSION}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Lisp that compiles to Lua
WWW=		https://fennel-lang.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake lua:51+,build,run

MAKE_ENV=	DESTDIR=${STAGEDIR} \
		LUA=${LUA_CMD} \
		LUA_DIR=${LOCALBASE} \
		LUA_INCLUDE_DIR=${LUA_INCDIR} \
		LUA_VERSION=${LUA_VER} \
		MAN_DIR=${PREFIX}/share \
		NATIVE_LUA_LIB=${LUA_LIBDIR}/liblua-${LUA_VER}.a \
		STATIC_LUA_LIB=${LUA_LIBDIR}/liblua-${LUA_VER}.a

ALL_TARGET=	build
TEST_TARGET=	test

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
