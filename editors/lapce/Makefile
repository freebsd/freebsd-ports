PORTNAME=	lapce
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1	# remove openssl-src-* from CARGO-CRATES each update \
			  remove patch-lapce-data_src_config.rs rust >= 1.64.0
CATEGORIES=	editors

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Lightning-fast and Powerful Code Editor
WWW=		https://lapce.dev/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON_i386=	doesn't build: [zstd-sys 2.0.1+zstd.1.5.2] AR_i686_unknown_freebsd = None

BUILD_DEPENDS=	p5-Cairo-GObject>0:devel/p5-Cairo-GObject \
		p5-FindBin-libs>0:devel/p5-FindBin-libs
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo gmake gnome localbase:ldflags perl5 pkgconfig ssl
USE_GITHUB=	yes
USE_GNOME=	atk gdkpixbuf2 gtk30 pango

PLIST_FILES=	bin/lapce \
		bin/lapce-proxy

#patch druid manually since it's not yet patched upstream
post-patch:
	@${FIND} ${WRKSRC}/../druid-281fe4bc56a198c7b5da90f65d4047a88153170e \
		 -name "*.toml" -o -name "*.rs" | ${XARGS} ${REINPLACE_CMD} -i '' -e 's|openbsd|freebsd|g'

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lapce
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lapce-proxy

.include <bsd.port.mk>
