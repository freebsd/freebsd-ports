PORTNAME=	gbump
PORTVERSION=	1.0.9
PORTREVISION=	5
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

BROKEN_SSL=	openssl openssl31
BROKEN_SSL_REASON=	Fails to find OpenSSL development headers

CARGO_CRATES=	aho-corasick-1.0.2 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		cc-1.0.79 \
		clap-3.2.25 \
		clap_lex-0.2.4 \
		form_urlencoded-1.2.0 \
		git2-0.17.2 \
		hashbrown-0.12.3 \
		hermit-abi-0.1.19 \
		idna-0.4.0 \
		indexmap-1.9.3 \
		jobserver-0.1.26 \
		libc-0.2.146 \
		libgit2-sys-0.15.2+1.6.4 \
		libssh2-sys-0.3.0 \
		libz-sys-1.1.9 \
		log-0.4.18 \
		memchr-2.5.0 \
		openssl-probe-0.1.5 \
		openssl-sys-0.9.88 \
		os_str_bytes-6.5.0 \
		percent-encoding-2.3.0 \
		pkg-config-0.3.27 \
		regex-1.8.4 \
		regex-syntax-0.7.2 \
		strsim-0.10.0 \
		termcolor-1.2.0 \
		textwrap-0.16.0 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		unicode-bidi-0.3.13 \
		unicode-normalization-0.1.22 \
		url-2.4.0 \
		vcpkg-0.2.15 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/gbump

.include <bsd.port.options.mk>

.if ( ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400092 && ${SSL_DEFAULT} == base ) || ${SSL_DEFAULT:Mopenssl} || ${SSL_DEFAULT:Mopenssl3*}
BROKEN_SSL=	base openssl openssl31
BROKEN_SSL_REASON=	Fails to find OpenSSL 3 development headers
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gbump

.include <bsd.port.mk>
