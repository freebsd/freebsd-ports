PORTNAME=	cxx-rust-cssparser
PORTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	KDE/stable/cxx-rust-cssparser
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} # workaround for USES=cargo

MAINTAINER=	kde@FreeBSD.org
COMMENT=	C++ library for parsing CSS using the Rust cssparser crate
WWW=		https://invent.kde.org/libraries/cxx-rust-cssparser

BUILD_DEPENDS=	${LOCALBASE}/share/cmake/Corrosion.cmake:devel/corrosion

USES=		cargo cmake kde:6 tar:xz
USE_KDE=	ecm:build
USE_LDCONFIG=	yes

CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_SRC_SUBDIR=	rust
CARGO_TARGET_DIR=	${WRKSRC}/target

CMAKE_OFF=	BUILD_DOCS

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

.include <bsd.port.mk>
