# $FreeBSD$

PORTNAME=	puppetdb-cli
PORTVERSION=	1.2.5
PORTREVISION=	7
CATEGORIES=	databases

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	PuppetDB CLI Tooling

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_SSL=				libressl libressl-devel openssl111
BROKEN_SSL_REASON_libressl=		Needs an old version of OpenSSL (older than 1.1)
BROKEN_SSL_REASON_libressl-devel=	Needs an old version of OpenSSL (older than 1.1)
BROKEN_SSL_REASON_openssl111=		Needs an older version of OpenSSL (older than 1.1)

USES=		cargo perl5
USE_GITHUB=	yes
USE_PERL5=	build

GH_ACCOUNT=	puppetlabs

CARGO_CRATES=	advapi32-sys-0.2.0 \
		aho-corasick-0.6.4 \
		antidote-1.0.0 \
		base64-0.6.0 \
		bitflags-0.7.0 \
		bitflags-0.9.1 \
		byteorder-1.2.1 \
		cc-1.0.3 \
		docopt-0.7.0 \
		dtoa-0.4.2 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fuchsia-zircon-0.2.1 \
		fuchsia-zircon-sys-0.2.0 \
		httparse-1.2.3 \
		hyper-0.10.13 \
		hyper-openssl-0.2.7 \
		idna-0.1.4 \
		itoa-0.3.4 \
		kernel32-sys-0.2.2 \
		kitchensink-0.4.2 \
		ktmw32-sys-0.1.0 \
		language-tags-0.2.2 \
		lazy_static-0.2.11 \
		libc-0.2.49 \
		log-0.3.8 \
		matches-0.1.6 \
		memchr-2.0.1 \
		mime-0.2.6 \
		mime_guess-1.8.3 \
		multipart-0.12.0 \
		num-traits-0.1.41 \
		num_cpus-1.7.0 \
		ole32-sys-0.2.0 \
		openssl-0.9.22 \
		openssl-sys-0.9.22 \
		percent-encoding-1.0.1 \
		phf-0.7.21 \
		phf_codegen-0.7.21 \
		phf_generator-0.7.21 \
		phf_shared-0.7.21 \
		pkg-config-0.3.9 \
		rand-0.3.18 \
		redox_syscall-0.1.32 \
		regex-0.2.3 \
		regex-syntax-0.4.1 \
		rustc-serialize-0.3.24 \
		safemem-0.2.0 \
		serde-1.0.23 \
		serde-transcode-1.0.0 \
		serde_json-1.0.7 \
		shell32-sys-0.1.1 \
		siphasher-0.2.2 \
		strsim-0.6.0 \
		tempdir-0.3.5 \
		thread_local-0.3.4 \
		time-0.1.38 \
		traitobject-0.1.0 \
		typeable-0.1.2 \
		unicase-1.4.2 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.5 \
		unreachable-1.0.0 \
		url-1.6.0 \
		userenv-sys-0.2.0 \
		utf8-ranges-1.0.0 \
		vcpkg-0.2.2 \
		version_check-0.1.3 \
		void-1.0.2 \
		winapi-0.2.8 \
		winapi-build-0.1.1 \
		winreg-0.4.0

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200085 && ${SSL_DEFAULT} == base
BROKEN=		Needs an older version of OpenSSL (older than 1.1)
.endif

PLIST_FILES=	bin/puppet-db \
		bin/puppet-query \
		man/man8/puppet-db.8.gz \
		man/man8/puppet-query.8.gz \
		man/man8/puppetdb_conf.8.gz

post-patch:
	${REINPLACE_CMD} -e 's|/etc/puppetlabs|/usr/local/etc|' \
		${WRKSRC}/cargo-crates/kitchensink-0.4.2/src/utils.rs \
		${WRKSRC}/man/puppetdb_conf.pod
	${REINPLACE_CMD} -e 's|\$${outpath}/share/|$${outpath}/|' \
		${WRKSRC}/pod2man.sh

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/puppet-db
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/puppet-query
	cd ${WRKSRC} && ./pod2man.sh ${STAGEDIR}${MANPREFIX}

.include <bsd.port.mk>
