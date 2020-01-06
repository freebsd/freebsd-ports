# $FreeBSD$

PORTNAME=	sysctl
PORTVERSION=	2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Small sysctl(3) interface for lua

LICENSE=	BSD2CLAUSE

USES=		lua pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	kAworu
GH_PROJECT=	lua-${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES
DOCSDIR=	${PREFIX}/share/doc/lua${LUA_VER_STR}/${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/lua${LUA_VER_STR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e "s/5.1/${LUA_VER}/g" ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/build/sysctl.so ${STAGEDIR}${LUA_MODLIBDIR}/sysctl.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/misc/*.lua ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
