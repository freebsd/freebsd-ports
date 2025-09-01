PORTNAME=	kibi
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
PORTREVISION=	41
CATEGORIES=	editors

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Tiny text editor written in Rust
WWW=		https://github.com/ilai-deutel/kibi

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ilai-deutel

CARGO_CRATES=	bitflags-1.2.1 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		cloudabi-0.0.3 \
		getrandom-0.2.1 \
		lazy_static-1.4.0 \
		libc-0.2.86 \
		lock_api-0.3.4 \
		parking_lot-0.10.2 \
		parking_lot_core-0.7.2 \
		ppv-lite86-0.2.10 \
		proc-macro2-1.0.12 \
		quote-1.0.4 \
		rand-0.8.2 \
		rand_chacha-0.3.0 \
		rand_core-0.6.1 \
		rand_hc-0.3.0 \
		redox_syscall-0.1.56 \
		redox_syscall-0.2.4 \
		remove_dir_all-0.5.2 \
		scopeguard-1.1.0 \
		serial_test-0.5.1 \
		serial_test_derive-0.5.1 \
		smallvec-1.4.0 \
		syn-1.0.18 \
		tempfile-3.2.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.0 \
		wasi-0.10.1+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=		DOCS SYNTAX
OPTIONS_DEFAULT=	SYNTAX
OPTIONS_SUB=		yes

SYNTAX_DESC=	Install Syntax-highlighting ini files

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/src/unix.rs

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-SYNTAX-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} syntax.d ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
