# $FreeBSD$

PORTNAME=	libgit2
PORTVERSION=	0.21.0
CATEGORIES=	devel

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Portable, pure C implementation of the Git core

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	libgit2
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	28f087c

USES=		cmake
USE_LDCONFIG=	yes
USE_PYTHON_BUILD=	yes
USE_OPENSSL=	yes

PLIST_SUB=	SHLIB_VER1=${PORTVERSION} \
		SHLIB_VER2=${PORTVERSION:R:E}

OPTIONS_DEFINE=	SSH
OPTIONS_DEFAULT=SSH
SSH_DESC=	Enable SSH support through libssh2

SSH_LIB_DEPENDS=	libssh2.so:${PORTSDIR}/security/libssh2
SSH_CMAKE_ON=		-DUSE_SSH=ON
SSH_CMAKE_OFF=		-DUSE_SSH=OFF

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
