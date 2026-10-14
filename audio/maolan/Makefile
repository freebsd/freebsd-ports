PORTNAME=	maolan
DISTVERSION=	0.3.2
CATEGORIES=	audio

MAINTAINER=	meka@sys.it.com
COMMENT=	Rust digital audio workstation
WWW=		https://maolan.rs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le riscv64

LIB_DEPENDS=	libjack.so:audio/jack

USES=		cargo localbase:ldflags pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	maolan

USE_XORG=	x11

CARGO_INSTALL_PATH=	. plugin-host

# The jitterentropy source must be compiled without optimizations, but the
# ports framework appends CFLAGS after aws-lc-sys's per-file -O0 flag.
MAKE_ENV+=	AWS_LC_SYS_NO_JITTER_ENTROPY=1

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/assets/desktop/maolan.desktop \
		${STAGEDIR}${PREFIX}/share/applications/maolan.desktop
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/assets/images/maolan-icon.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/maolan.svg

.include <bsd.port.mk>
