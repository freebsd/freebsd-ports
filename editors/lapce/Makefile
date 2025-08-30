PORTNAME=	lapce
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.4 # Cargo.lock patched: `make patch cargo-crates`
CATEGORIES=	editors

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Lightning-fast and Powerful Code Editor
WWW=		https://lapce.dev/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON_i386=	doesn't build: [zstd-sys 2.0.1+zstd.1.5.2] AR_i686_unknown_freebsd = None

LIB_DEPENDS=	libssh2.so:security/libssh2 \
		libgit2.so:devel/libgit2
RUN_DEPENDS=	xdg-desktop-portal>0:deskutils/xdg-desktop-portal

USES=		cargo desktop-file-utils dos2unix gmake localbase:ldflags perl5 pkgconfig ssl xorg
USE_GITHUB=	yes
USE_XORG=	xcb

DOS2UNIX_FILES=	cargo-crates/slotmap-1.0.7/src/lib.rs

PLIST_FILES=	bin/lapce \
		bin/lapce-proxy \
		share/applications/dev.lapce.lapce.desktop \
		share/pixmaps/dev.lapce.lapce.png

PORTSCOUT=	skipv:0.6.0

# OPENSSL_NO_VENDOR needs openssl-src present so I'm using Cargo.lock and lapce-proxy/Cargo.toml patches:
# first to not fetch openssl-src tarball and later to remove git2 ossl vendored feature.
CARGO_ENV=	RUSTC_BOOTSTRAP=1 OPENSSL_NO_VENDOR=1

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/extra/images/logo.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/dev.lapce.lapce.png
	${INSTALL_DATA} ${WRKSRC}/extra/linux/dev.lapce.lapce.desktop \
		${STAGEDIR}${PREFIX}/share/applications

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/cargo-crates/fontdb-0.16.2/src/lib.rs

.include <bsd.port.mk>
