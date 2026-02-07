# Also update devel/libgit2-glib, devel/py-pygit2
# Make sure you bump revision of depending ports, if SONAME changes
# objdump -p libgit2.so |grep SONAME
# Tools/scripts/search_lib_depends_and_bump.sh devel/libgit2

PORTNAME=	libgit2
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.2
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Portable, pure C implementation of the Git core
WWW=		https://libgit2.org \
		https://libgit2.github.com/

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libllhttp.so:www/llhttp

USES=		cmake:testing cpe localbase:ldflags pathfix pkgconfig \
		python:test ssl
PATHFIX_CMAKELISTSTXT=	PkgBuildConfig.cmake
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DREGEX_BACKEND=pcre2 \
		-DUSE_HTTP_PARSER=llhttp \
		-DCMAKE_CTEST_ARGUMENTS="-E;'online|gitdaemon|ssh|proxy|auth_clone'" \
		-DOPENSSL_ROOT_DIR=${OPENSSLBASE} \
		-DOPENSSL_ENGINES_DIR=${ENGINESDIR}

CMAKE_OFF=	BUILD_TESTS

CMAKE_TESTING_ON=	BUILD_TESTS

PLIST_SUB=	DISTVERSION=${DISTVERSION} \
		SHLIB_VER=${DISTVERSION:R}

OPTIONS_DEFINE=	SSH
OPTIONS_DEFAULT=SSH
SSH_DESC=	Enable SSH support through libssh2

SSH_LIB_DEPENDS=	libssh2.so:security/libssh2
SSH_CMAKE_ON=		-DUSE_SSH=libssh2

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
post-patch:
	@${REINPLACE_CMD} -e "/LIBGIT2_PC_REQUIRES.*openssl/ d" \
		${WRKSRC}/cmake/SelectHTTPSBackend.cmake
.endif

.include <bsd.port.post.mk>
