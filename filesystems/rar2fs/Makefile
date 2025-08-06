PORTNAME=	rar2fs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.29.7
PORTREVISION=	5
CATEGORIES=	filesystems
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	n_carlsson@outlook.com
COMMENT=	Mount RAR archives as file system
WWW=		https://hasse69.github.io/rar2fs/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${NONEXISTENT}:${LIBUNRAR_PORT}:patch
LIB_DEPENDS=	libunrar.so:${LIBUNRAR_PORT}

USES=		autoreconf compiler:c11 fuse gmake
USE_GITHUB=	yes
GH_ACCOUNT=	hasse69

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static-unrar \
		--with-fuse=${LOCALBASE}/include/fuse \
		--with-fuse-lib=${LOCALBASE}/lib \
		--with-unrar=`${MAKE} -C ${PORTSDIR}/${LIBUNRAR_PORT} -VWRKSRC` \
		--with-unrar-lib=${LOCALBASE}/lib
CONFIGURE_ENV=	LIBUNRAR_PKG=${LIBUNRAR_PKG}

PLIST_FILES=	bin/${PORTNAME} \
		bin/mkr2i \
		share/man/man1/rar2fs.1.gz

LIBUNRAR_PORT=	archivers/libunrar
LIBUNRAR_PKG=	${LIBUNRAR_PORT:S|archivers/||}

.include <bsd.port.mk>
