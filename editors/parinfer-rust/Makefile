# $FreeBSD$

PORTNAME=	parinfer-rust
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0-198
DISTVERSIONSUFFIX=	-g506ae2b
PORTREVISION=	3
CATEGORIES=	editors

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Infer parentheses for Clojure, Lisp, and Scheme

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	eraserhd
USE_LDCONFIG=	yes

CARGO_CRATES=	base-x-0.2.2 \
		discard-1.0.3 \
		dtoa-0.4.2 \
		getopts-0.2.18 \
		itoa-0.4.1 \
		libc-0.2.49 \
		proc-macro2-0.2.3 \
		proc-macro2-0.3.8 \
		quote-0.4.2 \
		quote-0.5.2 \
		serde-1.0.55 \
		serde_derive-1.0.55 \
		serde_json-1.0.17 \
		stdweb-0.4.5 \
		stdweb-derive-0.4.0 \
		stdweb-internal-macros-0.1.0 \
		syn-0.12.15 \
		syn-0.13.10 \
		unicode-segmentation-1.2.1 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		winapi-0.3.6 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/parinfer-rust \
		lib/libparinfer_rust.so \
		share/kak/rc/extra/parinfer.kak \
		share/vim/vimfiles/doc/parinfer.txt \
		share/vim/vimfiles/plugin/parinfer.vim

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/parinfer-rust
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/*/libparinfer_rust.so \
		${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/kak/rc/extra \
		${STAGEDIR}${PREFIX}/share/vim/vimfiles/doc \
		${STAGEDIR}${PREFIX}/share/vim/vimfiles/plugin
	${INSTALL_DATA} ${WRKSRC}/rc/parinfer.kak \
		${STAGEDIR}${PREFIX}/share/kak/rc/extra
	${INSTALL_DATA} ${WRKSRC}/doc/parinfer.txt \
		${STAGEDIR}${PREFIX}/share/vim/vimfiles/doc
	${INSTALL_DATA} ${WRKSRC}/plugin/parinfer.vim \
		${STAGEDIR}${PREFIX}/share/vim/vimfiles/plugin

.include <bsd.port.mk>
