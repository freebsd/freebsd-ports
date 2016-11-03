# $FreeBSD$

PORTNAME=	libgit2
PORTVERSION=	0.24.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Portable, pure C implementation of the Git core

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	libgit2

USES=		cmake pathfix pkgconfig python:build
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION} SHLIB_VER=${PORTVERSION:R:E}

OPTIONS_DEFINE=	SSH THREADS CURL
OPTIONS_DEFAULT=SSH THREADS CURL
SSH_DESC=	Enable SSH support through libssh2
CURL_DESC=	Enable HTTP support through cURL

SSH_LIB_DEPENDS=	libssh2.so:security/libssh2
SSH_CMAKE_ON=		-DUSE_SSH=ON
SSH_CMAKE_OFF=		-DUSE_SSH=OFF
THREADS_CMAKE_ON=	-DTHREADSAFE=ON
THREADS_CMAKE_OFF=	-DTHREADSAFE=OFF
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CMAKE_ON=		-DCURL=ON
CURL_CMAKE_OFF=		-DCURL=OFF

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "/LIBGIT2_PC_REQUIRES.*zlib/ d" ${WRKSRC}/CMakeLists.txt
.if ${SSL_DEFAULT} == base
	@${REINPLACE_CMD} -e "/LIBGIT2_PC_REQUIRES.*openssl/ d" \
		${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
