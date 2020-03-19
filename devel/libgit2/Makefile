# $FreeBSD$

# Also update devel/libgit2-glib, devel/rubygem-rugged, devel/py-pygit2
# Make sure you bump revision of depending ports, if SONAME changes
# objdump -p libgit2.so |grep SONAME
# Tools/scripts/search_lib_depends_and_bump.sh devel/libgit2

PORTNAME=	libgit2
PORTVERSION=	0.99.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libgit2/libgit2/releases/download/v${PORTVERSION}/

PATCH_SITES=	https://github.com/libgit2/libgit2/commit/
PATCHFILES=	3828ea67b97fc56dead976f319792ead3aa7e623.patch:-p1 \
		6d25dbdc5c3924336f61bc6091df64821acb95f2.patch:-p1

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Portable, pure C implementation of the Git core

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		cmake pkgconfig ssl
USE_LDCONFIG=	yes
CMAKE_OFF=	BUILD_CLAR

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		SHLIB_VER=${PORTVERSION:R}

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
		${WRKSRC}/cmake/Modules/SelectHTTPSBackend.cmake
.endif

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} \
		-DBUILD_CLAR=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.post.mk>
