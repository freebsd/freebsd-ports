PORTNAME=	amber
DISTVERSION=	0.3.2-alpha
PORTREVISION=	1
CATEGORIES=	lang
PKGNAMESUFFIX=	-language

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Amber: the programming language compiled to bash
WWW=		https://amber-lang.com

LICENSE=	GPLv3

RUN_DEPENDS=	bash:shells/bash

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	Ph0enixKM
GH_PROJECT=	Amber

CARGO_CRATES=	anstream-0.6.14 \
		anstyle-1.0.7 \
		anstyle-parse-0.2.4 \
		anstyle-query-1.0.3 \
		anstyle-wincon-3.0.3 \
		bitflags-2.5.0 \
		capitalize-0.1.0 \
		cfg-if-1.0.0 \
		clap-4.5.4 \
		clap_builder-4.5.2 \
		clap_derive-4.5.4 \
		clap_lex-0.7.0 \
		colorchoice-1.0.1 \
		colored-2.1.0 \
		either-1.12.0 \
		errno-0.3.9 \
		fastrand-2.1.0 \
		heck-0.5.0 \
		heraclitus-compiler-1.5.8 \
		is_terminal_polyfill-1.70.0 \
		itertools-0.11.0 \
		lazy_static-1.4.0 \
		libc-0.2.155 \
		linux-raw-sys-0.4.14 \
		pad-0.1.6 \
		proc-macro2-1.0.84 \
		quote-1.0.36 \
		rustix-0.38.34 \
		similar-string-1.4.3 \
		strsim-0.11.1 \
		syn-2.0.66 \
		tempfile-3.10.1 \
		unicode-ident-1.0.12 \
		unicode-width-0.1.12 \
		utf8parse-0.2.1 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.5 \
		windows_i686_gnullvm-0.52.5 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.5 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.5

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|"/bin/bash"|"${LOCALBASE}/bin/bash"|' ${WRKSRC}/src/compiler.rs

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
