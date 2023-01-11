PORTNAME=	cargo-c
DISTVERSION=	0.9.15
DISTVERSIONSUFFIX=	+cargo-0.67
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
# XXX Teach USES=cargo to have proper default
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

PATCH_SITES=	https://github.com/lu-zero/${PORTNAME}/commit/
PATCHFILES+=	4ec3bb5bf198.patch:-p1 # https://github.com/lu-zero/cargo-c/pull/303

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Cargo C-ABI helpers
WWW=		https://github.com/lu-zero/cargo-c

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libcurl.so:ftp/curl \
		libssh2.so:security/libssh2

USES=		cargo ssl
PLIST_FILES=	bin/cargo-capi \
		bin/cargo-cbuild \
		bin/cargo-cinstall \
		bin/cargo-ctest \
		${NULL}

post-patch:
	@${REINPLACE_CMD} -e 's,libdir.join("pkgconfig,prefix.join("libdata/pkgconfig,' \
		${WRKSRC}/src/install.rs

.include <bsd.port.mk>
