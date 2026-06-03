PORTNAME=	gram
DISTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	https://codeberg.org/GramEditor/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/:main
PKGNAMESUFFIX=	-text-editor
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:main

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fork of the Zed code editor without AI or telemetry
WWW=		https://codeberg.org/GramEditor/gram

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE-GPL

BUILD_DEPENDS=	protoc:devel/protobuf
LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2 \
		libzstd.so:archivers/zstd \
		libxkbcommon.so:x11/libxkbcommon \
		libxkbcommon-x11.so:x11/libxkbcommon

USES=		cargo ssl xorg
USE_XORG=	xcb

CARGO_ENV=	LIBGIT2_NO_VENDOR=1 \
		LIBSSH2_SYS_USE_PKG_CONFIG=1 \
		OPENSSL_NO_VENDOR=1
CARGO_INSTALL_PATH=	crates/gram

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
