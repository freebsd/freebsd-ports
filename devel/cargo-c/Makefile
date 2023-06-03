PORTNAME=	cargo-c
DISTVERSION=	0.9.20
DISTVERSIONSUFFIX=	+cargo-0.71
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
# XXX Teach USES=cargo to have proper default
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Cargo C-ABI helpers
WWW=		https://github.com/lu-zero/cargo-c

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cargo ssl
PLIST_FILES=	bin/cargo-capi \
		bin/cargo-cbuild \
		bin/cargo-cinstall \
		bin/cargo-ctest \
		${NULL}

post-patch:
	@${REINPLACE_CMD} -e 's,libdir.join("pkgconfig,prefix.join("libdata/pkgconfig,' \
		${WRKSRC}/src/install.rs
# XXX Need devel/libgit2 >= 1.6.4; libgit2 depends on libssh2, so bundle both
	@${REINPLACE_CMD} 's/if try_to_use_system_libgit2/if false/' \
		${WRKSRC}/cargo-crates/libgit2-sys-*/build.rs
	@${REINPLACE_CMD} '/env::var/s/LIBSSH2.*PKG/disabled_&/' \
		${WRKSRC}/cargo-crates/libssh2-sys-*/build.rs

.include <bsd.port.mk>
