# Created by: Leo Vandewoestijne <freebsd@dns.company>
# $FreeBSD$

PORTNAME=	cqueues
DISTVERSIONPREFIX=	rel-
DISTVERSION=	20200603
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	freebsd@dns.company
COMMENT=	Constant queues lib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake lua:51+,module ssl
USE_LDCONFIG=	{LUA_MODLIBDIR}
LDFLAGS+=	-Wl,-soname,liblua-${PORTNAME}.so.${LUA_VER_STR}

USE_GITHUB=	yes
GH_ACCOUNT=	wahern

SONAME=		${STAGEDIR}${PREFIX}/lib/liblua-${PORTNAME}.so

post-install:
	${MV} ${STAGEDIR}${LUA_MODLIBDIR}/_${PORTNAME}.so ${SONAME}.${LUA_VER_STR}
	${STRIP_CMD} ${SONAME}.${LUA_VER_STR}
	${RLN} ${SONAME}.${LUA_VER_STR} ${SONAME}

.include <bsd.port.mk>
