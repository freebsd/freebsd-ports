PORTNAME=	avfs
PORTVERSION=	1.4.0
CATEGORIES=	filesystems sysutils
MASTER_SITES=	SF/avf/${PORTNAME}/${PORTVERSION} \
		${WWW:[2]}downloads/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Virtual File System library
WWW=		https://avf.sourceforge.net/ \
		http://www.boomerangsworld.de/cms/avfs/

# FUSE daemon is licensed as GPLv2, shared library is LGPLv2
LICENSE=	LGPL20 GPLv2
LICENSE_COMB=	multi

RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

USES=		iconv libtool perl5 pkgconfig shebangfix tar:bz2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL="${PERL}"
USE_LDCONFIG=	yes
USE_PERL5=	run
SHEBANG_FILES=	extfs/uimg scripts/umountavfs scripts/mountavfs
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DAV FUSE LZIP ZSTD
OPTIONS_DEFAULT=	LZIP ZSTD
OPTIONS_SUB=	yes

DAV_DESC=	Build the DAV module (requires libneon)
DAV_LIB_DEPENDS=	libneon.so:www/neon
DAV_CONFIGURE_ENABLE=	dav

FUSE_CONFIGURE_ENABLE=	fuse
FUSE_USES=	fuse

LZIP_DESC=	Lzip compression support via liblz
LZIP_LIB_DEPENDS=	liblz.so:archivers/lzlib
LZIP_CONFIGURE_WITH=	lzip

ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_CONFIGURE_WITH=	zstd

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

post-patch:
	@${REINPLACE_CMD} -e '/#include <stddef\.h>/ { x; \
		s/^/#include <limits.h>/; G; }' ${WRKSRC}/fuse/avfsd.c
	@${REINPLACE_CMD} -e '/#include/s,neon/,,' ${WRKSRC}/modules/dav*.?

.include <bsd.port.mk>
