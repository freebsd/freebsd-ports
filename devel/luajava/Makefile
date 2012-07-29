# New ports collection makefile for:   luajava
# Date created:        5 December 2007
# Whom:                sunghyuk
#
# $FreeBSD$
#

PORTNAME=	luajava
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	http://luaforge.net/frs/download.php/2105/

MAINTAINER=	sunghyuk@gmail.com
COMMENT=	Lua scripting tool for Java

USE_GMAKE=	yes
USE_LUA=	5.1
LUA_COMPS=	lua
.if ${USE_LUA} == 5.0
LUA_COMPS+=	compat51
.endif
USE_JAVA=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

ALL_TARGET=	run
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.*

post-patch:
	@${REINPLACE_CMD} -e 's|%%LUA_DIR%%|${PREFIX}|' ${WRKSRC}/config
	@${REINPLACE_CMD} -e 's|%%LUA_LIBDIR%%|${LUA_LIBDIR}|' ${WRKSRC}/config
	@${REINPLACE_CMD} -e 's|%%LUA_INCDIR%%|${LUA_INCDIR}|' ${WRKSRC}/config
	@${REINPLACE_CMD} -e 's|%%JAVA_HOME%%|${JAVA_HOME}|' ${WRKSRC}/config
	@${REINPLACE_CMD} -e 's|linux|freebsd|' ${WRKSRC}/config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libluajava-1.1.so ${LUA_MODLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/luajava-1.1.jar ${JAVAJARDIR}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.mk>
