# $FreeBSD$

PORTNAME=	gbump
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nbari@tequila.io
COMMENT=	Git tag semantic version bumper

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo ssl

CARGO_CRATES=	aho-corasick-0.7.6 \
		ansi_term-0.11.0 \
		atty-0.2.13 \
		autocfg-0.1.7 \
		bitflags-1.2.1 \
		cc-1.0.47 \
		cfg-if-0.1.10 \
		clap-2.33.0 \
		getrandom-0.1.13 \
		git2-0.10.1 \
		hermit-abi-0.1.3 \
		idna-0.2.0 \
		jobserver-0.1.17 \
		lazy_static-1.4.0 \
		libc-0.2.65 \
		libgit2-sys-0.9.1 \
		libssh2-sys-0.2.13 \
		libz-sys-1.0.25 \
		log-0.4.8 \
		matches-0.1.8 \
		maybe-uninit-2.0.0 \
		memchr-2.2.1 \
		num_cpus-1.11.1 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.52 \
		percent-encoding-2.1.0 \
		pkg-config-0.3.17 \
		regex-1.3.1 \
		regex-syntax-0.6.12 \
		smallvec-0.6.13 \
		strsim-0.8.0 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.9 \
		unicode-width-0.1.6 \
		url-2.1.0 \
		vcpkg-0.2.7 \
		vec_map-0.8.1 \
		wasi-0.7.0 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/gbump

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gbump

.include <bsd.port.mk>
