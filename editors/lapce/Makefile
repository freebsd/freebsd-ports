PORTNAME=	lapce
PORTVERSION=	g20220826 # remove openssl-src-* from CARGO-CRATES each update
CATEGORIES=	editors

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Lightning-fast and Powerful Code Editor

LICENSE=	APACHE20

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON_i386=	doesn't build: [zstd-sys 2.0.1+zstd.1.5.2] AR_i686_unknown_freebsd = None

BUILD_DEPENDS=	p5-Cairo-GObject>0:devel/p5-Cairo-GObject \
		p5-FindBin-libs>0:devel/p5-FindBin-libs
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo gmake gnome localbase:ldflags perl5 pkgconfig ssl
USE_GITHUB=	yes
GH_TAGNAME=	5abf778
USE_GNOME=	atk gdkpixbuf2 gtk30 pango

PLIST_FILES=	bin/lapce \
		bin/lapce-proxy

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lapce
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lapce-proxy

.include <bsd.port.mk>
