# $FreeBSD$

PORTNAME=	libgit2
PORTVERSION=	0.22.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Portable, pure C implementation of the Git core

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	libgit2

USES=		cmake pkgconfig python:build
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

PLIST_SUB=	SHLIB_VER=${PORTVERSION:R:E}

OPTIONS_DEFINE=	SSH THREADS
OPTIONS_DEFAULT=SSH THREADS
SSH_DESC=	Enable SSH support through libssh2

SSH_LIB_DEPENDS=	libssh2.so:${PORTSDIR}/security/libssh2
SSH_CMAKE_ON=		-DUSE_SSH=ON
SSH_CMAKE_OFF=		-DUSE_SSH=OFF
THREADS_CMAKE_ON=	-DTHREADSAFE=ON
THREADS_CMAKE_OFF=	-DTHREADSAFE=OFF

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64: thread-local storage not supported
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/pkgconfig|/../libdata/pkgconfig|; \
		/LIBGIT2_PC_REQUIRES.*zlib/ d" ${WRKSRC}/CMakeLists.txt
.if defined(WITH_OPENSSL_BASE)
	@${REINPLACE_CMD} -e "/LIBGIT2_PC_REQUIRES.*openssl/ d" \
		${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
