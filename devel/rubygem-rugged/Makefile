# Also update devel/libgit2, devel/libgit2-glib, devel/py-pygit2

PORTNAME=	rugged
PORTVERSION=	1.7.2
PORTREVISION=	3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby bindings to the libgit2 library
WWW=		https://github.com/libgit2/rugged

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# switch to bundled libgit2 version as rugged does not support 1.8 version from ports (https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=282593)
#BUILD_DEPENDS=	libgit2>=${PORTVERSION:R}:devel/libgit2
#LIB_DEPENDS=	libgit2.so:devel/libgit2 \
#		libgmp.so:math/gmp
#CONFIGURE_ARGS=	--use-system-libraries
#USES=		gem pkgconfig
LIB_DEPENDS=	libssh2.so:security/libssh2

CONFIGURE_ARGS=	--with-ssh
USES=		cmake:indirect gem pkgconfig ssl

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/vendor/libgit2/build

.include <bsd.port.mk>
