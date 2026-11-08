PORTNAME=	ntfs2btrfs
PORTVERSION=	20260810
CATEGORIES=	filesystems sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	NTFS to Btrfs in-place conversion utility
WWW=		https://github.com/maharmstone/ntfs2btrfs

LICENSE=	GPLv2+

LIB_DEPENDS=	liblzo2.so:archivers/lzo2 libzstd.so:archivers/zstd

USES=		cmake llvm:min=17 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	maharmstone

PLIST_FILES=	sbin/${PORTNAME} share/man/man8/${PORTNAME}.8.gz

.include <bsd.port.mk>
