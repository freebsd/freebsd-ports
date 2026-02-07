PORTNAME=	zerofs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	filesystems sysutils

MAINTAINER=	stephan@lichtenauer.co.za
COMMENT=	ZeroFS is 9P/NFS/NBD on top of S3
WWW=		https://github.com/Barre/ZeroFS

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC:H}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	32-bit compilation is not supported

LIB_DEPENDS+=	libzstd.so:archivers/zstd

USES=		cargo gmake
USE_GITHUB=	yes
GH_ACCOUNT=	Barre
GH_PROJECT=	ZeroFS

RUSTFLAGS+=	--cfg tokio_unstable

WRKSRC_SUBDIR=	zerofs

PLIST_FILES=	bin/zerofs

.include <bsd.port.mk>
