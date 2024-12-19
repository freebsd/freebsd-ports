PORTNAME=	ntfs
PORTVERSION=	2022.10.3
PORTREVISION=	2
CATEGORIES=	filesystems
MASTER_SITES=	https://download.tuxera.com/opensource/
PKGNAMEPREFIX=	fusefs-
DISTNAME=	${PORTNAME}-3g_ntfsprogs-${PORTVERSION}

MAINTAINER=	freebsd@dussan.org
COMMENT=	Mount NTFS partitions (read/write) and disk images
WWW=		https://github.com/tuxera/ntfs-3g

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libuuid.so:misc/libuuid

USES=		fuse pkgconfig iconv libtool localbase:ldflags tar:tgz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--exec-prefix=${PREFIX} --disable-mount-helper \
		--disable-mtab --with-fuse=external --disable-ldconfig
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	CRYPTO DOCS EXTRAS LOCK UBLIO
OPTIONS_DEFAULT=EXTRAS LOCK UBLIO
OPTIONS_SUB=	yes

CRYPTO_DESC=	Enable crypto-related code and utilities
CRYPTO_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgnutls.so:security/gnutls \
			libgpg-error.so:security/libgpg-error
CRYPTO_CONFIGURE_ON=	--enable-crypto

EXTRAS_DESC=	Build and install extra NTFS utilities
EXTRAS_CONFIGURE_ON=	--enable-extras

LOCK_DESC=	Lock the device when mounting (avoids access)
LOCK_CFLAGS=	-DUSE_LOCK

UBLIO_DESC=	Enable user space cache for improved speed
UBLIO_EXTRA_PATCHES=	${FILESDIR}/extra-patch-ublio
UBLIO_LIB_DEPENDS=	libublio.so:devel/libublio
UBLIO_CFLAGS=	-DUSE_UBLIO

SUB_FILES=	pkg-message
DOCSDIR=	${PREFIX}/share/doc/ntfs-3g

post-patch:
	@${REINPLACE_CMD} -e 's|ENODATA|ENOATTR|' \
		${WRKSRC}/libntfs-3g/object_id.c \
		${WRKSRC}/libntfs-3g/reparse.c \
		${WRKSRC}/libntfs-3g/security.c
	@${REINPLACE_CMD} -e '/$$(MAKE).*install-exec-hook/d' \
		${WRKSRC}/libntfs-3g/Makefile.in

post-install-DOCS-on:
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
