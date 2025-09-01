PORTNAME=	gbump
PORTVERSION=	1.1.2
PORTREVISION=	18
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	nbari@tequila.io
COMMENT=	Git tag semantic version bumper
WWW=		https://github.com/nbari/gbump

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo localbase ssl

CARGO_CRATES=   aho-corasick-1.1.2 \
                anstream-0.6.5 \
                anstyle-1.0.4 \
                anstyle-parse-0.2.3 \
                anstyle-query-1.0.2 \
                anstyle-wincon-3.0.2 \
                bitflags-2.4.1 \
                cc-1.0.83 \
                cfg-if-1.0.0 \
                clap-4.4.11 \
                clap_builder-4.4.11 \
                clap_lex-0.6.0 \
                colorchoice-1.0.0 \
                foreign-types-0.3.2 \
                foreign-types-shared-0.1.1 \
                form_urlencoded-1.2.1 \
                git2-0.18.1 \
                idna-0.5.0 \
                jobserver-0.1.27 \
                libc-0.2.151 \
                libgit2-sys-0.16.1+1.7.1 \
                libssh2-sys-0.3.0 \
                libz-sys-1.1.12 \
                log-0.4.20 \
                memchr-2.6.4 \
                once_cell-1.19.0 \
                openssl-0.10.61 \
                openssl-macros-0.1.1 \
                openssl-probe-0.1.5 \
                openssl-src-300.2.1+3.2.0 \
                openssl-sys-0.9.97 \
                percent-encoding-2.3.1 \
                pkg-config-0.3.27 \
                proc-macro2-1.0.70 \
                quote-1.0.33 \
                regex-1.10.2 \
                regex-automata-0.4.3 \
                regex-syntax-0.8.2 \
                strsim-0.10.0 \
                syn-2.0.41 \
                tinyvec-1.6.0 \
                tinyvec_macros-0.1.1 \
                unicode-bidi-0.3.14 \
                unicode-ident-1.0.12 \
                unicode-normalization-0.1.22 \
                url-2.5.0 \
                utf8parse-0.2.1 \
                vcpkg-0.2.15 \
                windows-sys-0.52.0 \
                windows-targets-0.52.0 \
                windows_aarch64_gnullvm-0.52.0 \
                windows_aarch64_msvc-0.52.0 \
                windows_i686_gnu-0.52.0 \
                windows_i686_msvc-0.52.0 \
                windows_x86_64_gnu-0.52.0 \
                windows_x86_64_gnullvm-0.52.0 \
                windows_x86_64_msvc-0.52.0

PLIST_FILES=	bin/gbump

.include <bsd.port.mk>
