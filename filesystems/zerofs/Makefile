PORTNAME=	zerofs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.6
CATEGORIES=	filesystems sysutils

MAINTAINER=	stephan@lichtenauer.co.za
COMMENT=	ZeroFS is 9P/NFS/NBD on top of S3
WWW=		https://github.com/Barre/ZeroFS

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC:H}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	32-bit compilation is not supported

BUILD_DEPENDS+=	protoc:devel/protobuf
LIB_DEPENDS+=	libprotobuf.so:devel/protobuf \
		libzstd.so:archivers/zstd

USES=		cargo gmake
USE_GITHUB=	yes
GH_ACCOUNT=	Barre
GH_PROJECT=	ZeroFS

CARGO_ENV+=	PROTOC=${LOCALBASE}/bin/protoc
CARGO_BUILD_ARGS=	--no-default-features --features ""

RUSTFLAGS+=	--cfg tokio_unstable

WRKSRC_SUBDIR=	zerofs

PLIST_FILES=	bin/zerofs

post-extract:
	@cd ${WRKDIR} && \
		${MV} zerofs_arrow-rs-object-store-01b0349f126c9eda8e7ad8767c7e4868debe3602 arrow-rs-object-store-01b0349f126c9eda8e7ad8767c7e4868debe3602

.include <bsd.port.mk>
