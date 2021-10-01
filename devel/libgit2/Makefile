# Also update devel/libgit2-glib, devel/rubygem-rugged, devel/py-pygit2
# Make sure you bump revision of depending ports, if SONAME changes
# objdump -p libgit2.so |grep SONAME
# Tools/scripts/search_lib_depends_and_bump.sh devel/libgit2

PORTNAME=	libgit2
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Portable, pure C implementation of the Git core

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libhttp_parser.so:www/http-parser

USES=		cmake cpe pkgconfig ssl
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DREGEX_BACKEND=pcre2 -DUSE_HTTP_PARSER=system
CMAKE_OFF=	BUILD_CLAR

PLIST_SUB=	DISTVERSION=${DISTVERSION} \
		SHLIB_VER=${DISTVERSION:R}

OPTIONS_DEFINE=	SSH THREADS
OPTIONS_DEFAULT=SSH THREADS
SSH_DESC=	Enable SSH support through libssh2

SSH_LIB_DEPENDS=	libssh2.so:security/libssh2
SSH_CMAKE_BOOL=		USE_SSH
THREADS_CMAKE_BOOL=	THREADSAFE

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
post-patch:
	@${REINPLACE_CMD} -e "/LIBGIT2_PC_REQUIRES.*openssl/ d" \
		${WRKSRC}/cmake/SelectHTTPSBackend.cmake
.endif

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} \
		-DBUILD_CLAR=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} CTEST_OUTPUT_ON_FAILURE=1 ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.post.mk>
