PORTNAME=	ntfs2btrfs
PORTVERSION=	20230501
PORTREVISION=	1
CATEGORIES=	filesystems sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	NTFS to Btrfs in-place conversion utility
WWW=		https://github.com/maharmstone/ntfs2btrfs

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/fmt/format.h:devel/libfmt
LIB_DEPENDS=	liblzo2.so:archivers/lzo2 libzstd.so:archivers/zstd

USES=		cmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	maharmstone

PLIST_FILES=	sbin/${PORTNAME} share/man/man8/${PORTNAME}.8.gz

post-patch:
# One should not try to mmap(2) disk devices on FreeBSD, it won't work
	@${REINPLACE_CMD} -e '3449s,WIN32,_${OPSYS}__,' \
		${WRKSRC}/src/ntfs2btrfs.cpp

.include <bsd.port.mk>
