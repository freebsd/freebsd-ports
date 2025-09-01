PORTNAME=	dog
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
PORTREVISION=	44
CATEGORIES=	dns net

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Command-line DNS client
WWW=		https://dns.lookup.dog/

LICENSE=	EUPL12
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	ogham

CONFLICTS_INSTALL=	py*-datadog

CARGO_CRATES=	addr2line-0.14.0 \
		adler-0.2.3 \
		ansi_term-0.11.0 \
		ansi_term-0.12.1 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		backtrace-0.3.54 \
		bitflags-1.2.1 \
		byteorder-1.3.4 \
		cc-1.0.61 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		core-foundation-0.7.0 \
		core-foundation-sys-0.7.0 \
		ctor-0.1.16 \
		datetime-0.5.1 \
		difference-2.0.0 \
		failure-0.1.8 \
		failure_derive-0.1.8 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		getopts-0.2.21 \
		getrandom-0.1.15 \
		gimli-0.23.0 \
		hermit-abi-0.1.17 \
		httparse-1.3.4 \
		ipconfig-0.2.2 \
		itoa-0.4.6 \
		json-0.12.4 \
		lazy_static-1.4.0 \
		libc-0.2.80 \
		log-0.4.11 \
		miniz_oxide-0.4.3 \
		native-tls-0.2.4 \
		object-0.22.0 \
		openssl-0.10.30 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.58 \
		output_vt100-0.1.2 \
		pkg-config-0.3.19 \
		ppv-lite86-0.2.10 \
		pretty_assertions-0.6.1 \
		proc-macro2-1.0.24 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.57 \
		regex-1.4.2 \
		regex-syntax-0.6.21 \
		remove_dir_all-0.5.3 \
		rustc-demangle-0.1.18 \
		ryu-1.0.5 \
		schannel-0.1.19 \
		security-framework-0.4.4 \
		security-framework-sys-0.4.3 \
		serde-1.0.117 \
		serde_derive-1.0.117 \
		serde_json-1.0.59 \
		socket2-0.3.15 \
		syn-1.0.48 \
		synstructure-0.12.4 \
		tempfile-3.1.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		vcpkg-0.2.10 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		widestring-0.4.3 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winreg-0.6.2 \
		mutagen,mutagen-core,mutagen-transform@git+https://github.com/llogiq/mutagen\#c7abc956a10e8a3e2cc71f21279ea0a42f7b7c10

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=		COMPLETIONS DOCS
OPTIONS_DEFAULT=	COMPLETIONS

COMPLETIONS_DESC=		Install bash, fish and zsh shell completions
COMPLETIONS_PLIST_FILES=	share/bash-completion/completions/${PORTNAME} \
				share/fish/vendor_completions.d/${PORTNAME}.fish \
				share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.options.mk>

.if ( ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400092 && ${SSL_DEFAULT} == base ) || ${SSL_DEFAULT:Mopenssl} || ${SSL_DEFAULT:Mopenssl3*}
BROKEN=	Fails to detect OpenSSL 3.0.0 and later
.endif

post-install-COMPLETIONS-on:
.for _shell in bash fish zsh
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.${_shell} \
		${STAGEDIR}${PREFIX}/${COMPLETIONS_PLIST_FILES:M*${_shell}*}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
