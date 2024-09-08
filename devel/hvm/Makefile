PORTNAME=	hvm
DISTVERSION=	g20240518
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Massively parallel, optimal functional runtime in Rust
WWW=		https://higherorderco.com

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	HigherOrderCO
GH_PROJECT=	${PORTNAME:tu}
GH_TAGNAME=	c98deff

CARGO_CRATES=	TSPL-0.0.12 \
		anstream-0.6.14 \
		anstyle-1.0.7 \
		anstyle-parse-0.2.4 \
		anstyle-query-1.0.3 \
		anstyle-wincon-3.0.3 \
		cc-1.0.97 \
		clap-4.5.4 \
		clap_builder-4.5.2 \
		clap_lex-0.7.0 \
		colorchoice-1.0.1 \
		hermit-abi-0.3.9 \
		highlight_error-0.1.1 \
		is_terminal_polyfill-1.70.0 \
		libc-0.2.155 \
		num_cpus-1.16.0 \
		strsim-0.11.1 \
		utf8parse-0.2.1 \
		windows-sys-0.52.0 \
		windows-targets-0.52.5 \
		windows_aarch64_gnullvm-0.52.5 \
		windows_aarch64_msvc-0.52.5 \
		windows_i686_gnu-0.52.5 \
		windows_i686_gnullvm-0.52.5 \
		windows_i686_msvc-0.52.5 \
		windows_x86_64_gnu-0.52.5 \
		windows_x86_64_gnullvm-0.52.5 \
		windows_x86_64_msvc-0.52.5

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
