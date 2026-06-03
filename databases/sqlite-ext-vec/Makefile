PORTNAME=	sqlite-ext-vec
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.9
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Vector search SQLite extension
WWW=		https://github.com/asg017/sqlite-vec

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual

USES=		gmake localbase:ldflags sqlite:3
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	asg017
GH_PROJECT=	sqlite-vec

ALL_TARGET=	loadable shared static # 'static' and 'shared' are the static and shared libs with this extension
CFLAGS+=	-include sys/types.h # workaround for https://github.com/asg017/sqlite-vec/issues/287
MAKE_ARGS=	VERSION=${DISTVERSION}

BINARY_ALIAS=	gcc=${CC}

PLIST_FILES=	include/sqlite-vec.h \
		lib/libsqlite_vec0.a \
		lib/libsqlite_vec0.so \
		libexec/sqlite-ext/vec0.so

do-install:
	# install the extension
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/sqlite-ext
	${INSTALL_LIB} ${WRKSRC}/dist/vec0.so ${STAGEDIR}${PREFIX}/libexec/sqlite-ext
	# install the header and static library for users who want to build theor own SQLite code with this extension
	${MKDIR} ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/sqlite-vec.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_LIB} ${WRKSRC}/dist/libsqlite_vec0.so ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/dist/libsqlite_vec0.a ${STAGEDIR}${PREFIX}/lib/

do-test:
	@cd ${WRKSRC}/tests/minimum && \
		${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} \
			-DSQLITE_CORE \
			-I${WRKSRC} \
			demo.c \
			${WRKSRC}/dist/libsqlite_vec0.a \
			-lsqlite3 -lm -lpthread \
			-o demo && \
		./demo

.include <bsd.port.mk>
