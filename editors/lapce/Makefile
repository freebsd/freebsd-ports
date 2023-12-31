PORTNAME=	lapce
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1 # Cargo.lock patched: `make patch cargo-crates`
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

USES=		cargo gmake localbase:ldflags pkgconfig ssl xorg
USE_GITHUB=	yes
USE_XORG=	xcb

PLIST_FILES=	bin/lapce \
		bin/lapce-proxy

PORTSCOUT=	skipv:0.6.0

# Do not LTO and strip binaries while WIP:
# https://github.com/lapce/lapce/issues/2748
LTO_UNSAFE=	yes
#post-install:
#	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lapce
#	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lapce-proxy

.include <bsd.port.mk>
