PORTNAME=	luajava
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	http://luaforge.net/frs/download.php/2105/

MAINTAINER=	sunghyuk@gmail.com
COMMENT=	Lua scripting tool for Java

USES=		gmake dos2unix lua:51
USE_JAVA=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

ALL_TARGET=	run
DOS2UNIX_REGEX=	.*\.*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION:M*7*}
PLIST_SUB+=	JDK17=""
.else
PLIST_SUB+=	JDK17="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LUA_DIR%%|${PREFIX}|' ${WRKSRC}/config
	@${REINPLACE_CMD} -e 's|%%LUA_LIBDIR%%|${LUA_LIBDIR}|' ${WRKSRC}/config
	@${REINPLACE_CMD} -e 's|%%LUA_INCDIR%%|${LUA_INCDIR}|' ${WRKSRC}/config
	@${REINPLACE_CMD} -e 's|%%LUA_VER%%|${LUA_VER}|' ${WRKSRC}/config
	@${REINPLACE_CMD} -e 's|%%JAVA_HOME%%|${JAVA_HOME}|' ${WRKSRC}/config
	@${REINPLACE_CMD} -e 's|linux|freebsd|' ${WRKSRC}/config

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/libluajava-1.1.so ${STAGEDIR}${LUA_MODLIBDIR}
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/luajava-1.1.jar ${STAGEDIR}${JAVAJARDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
