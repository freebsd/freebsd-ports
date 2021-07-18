PORTNAME=	stack
PORTVERSION=	2.7.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Cross-platform program for developing Haskell programs

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		gmake:devel/gmake \
		${LOCALBASE}/lib/compat/libffi.so.6:devel/libffi321

USE_GITHUB=	yes
GH_ACCOUNT=	commercialhaskell
GH_PROJECT=	stack

USES=		cabal gmake perl5

USE_PERL5=	run

CABAL_FLAGS=	-support_aesni

USE_CABAL=	Glob-0.10.1 \
		StateVar-1.2.1 \
		aeson-1.5.6.0_1 \
		annotated-wl-pprint-0.7.0_1 \
		ansi-terminal-0.11 \
		ansi-wl-pprint-0.6.9_2 \
		appar-0.1.8 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.0.2_1 \
		async-2.2.3 \
		attoparsec-0.14.1 \
		attoparsec-iso8601-1.0.2.0_1 \
		auto-update-0.1.6 \
		base-compat-0.11.2 \
		base-compat-batteries-0.11.2 \
		base-orphans-0.8.4 \
		base16-bytestring-1.0.1.0 \
		base64-bytestring-1.2.0.1 \
		basement-0.0.12_1 \
		bifunctors-5.5.11 \
		blaze-builder-0.4.2.1 \
		blaze-html-0.9.1.2_1 \
		blaze-markup-0.8.2.8 \
		byteorder-1.0.4 \
		casa-client-0.0.1 \
		casa-types-0.0.2 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.1 \
		clock-0.8.2 \
		cmdargs-0.10.21 \
		colour-2.3.5 \
		comonad-5.0.8 \
		conduit-1.3.4.1 \
		conduit-combinators-1.3.0 \
		conduit-extra-1.3.5 \
		connection-0.3.1_1 \
		contravariant-1.5.3 \
		cookie-0.4.5 \
		cryptohash-sha256-0.11.102.0 \
		cryptonite-0.29 \
		cryptonite-conduit-0.2.2_1 \
		data-default-class-0.1.2.0 \
		data-fix-0.3.1 \
		digest-0.0.1.2 \
		distributive-0.6.2.1 \
		dlist-1.0 \
		easy-file-0.2.2 \
		echo-0.1.4 \
		ed25519-0.0.5.0_3 \
		either-5.0.1.1_1 \
		extra-1.7.9 \
		fast-logger-3.0.5 \
		file-embed-0.0.14.0 \
		filelock-0.1.1.5 \
		filtrable-0.1.6.0 \
		fsnotify-0.3.0.1_1 \
		generic-deriving-1.14_1 \
		githash-0.1.5.0 \
		hackage-security-0.6.0.1_5 \
		hashable-1.3.1.0 \
		hi-file-parser-0.1.2.0 \
		hourglass-0.2.12 \
		hpack-0.34.4 \
		hsc2hs-0.68.7_1 \
		http-api-data-0.4.3_2 \
		http-client-0.7.8 \
		http-client-tls-0.3.5.3_1 \
		http-conduit-2.3.8 \
		http-download-0.2.0.0 \
		http-types-0.12.3 \
		indexed-traversable-0.1.1 \
		infer-license-0.2.0 \
		integer-logarithms-1.0.3.1 \
		iproute-1.7.11 \
		libyaml-0.1.2 \
		lift-type-0.1.0.1 \
		lifted-base-0.2.3.12 \
		lukko-0.1.1.3_1 \
		megaparsec-9.0.1_1 \
		memory-0.16.0 \
		microlens-0.4.12.0 \
		microlens-mtl-0.2.0.1 \
		microlens-th-0.4.3.10 \
		mime-types-0.1.0.9 \
		mintty-0.1.2 \
		monad-control-1.0.2.3 \
		monad-logger-0.3.36 \
		monad-loops-0.4.3 \
		mono-traversable-1.0.15.1 \
		mustache-2.3.1 \
		neat-interpolation-0.5.1.2 \
		network-3.1.2.1_1 \
		network-uri-2.6.4.1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2 \
		open-browser-0.2.1.0 \
		optparse-applicative-0.16.1.0 \
		optparse-simple-0.1.1.3 \
		pantry-0.5.2.1 \
		parser-combinators-1.3.0 \
		path-0.8.0_1 \
		path-io-1.6.2 \
		path-pieces-0.2.1_1 \
		pem-0.2.4 \
		persistent-2.13.0.1 \
		persistent-sqlite-2.13.0.0_1 \
		persistent-template-2.12.0.0 \
		primitive-0.7.1.0_2 \
		profunctors-5.6.2 \
		project-template-0.2.1.0 \
		random-1.2.0_5 \
		regex-applicative-0.3.4 \
		regex-applicative-text-0.1.0.1_5 \
		resource-pool-0.2.3.2 \
		resourcet-1.2.4.2 \
		retry-0.8.1.2 \
		rio-0.1.20.0 \
		rio-orphans-0.1.2.0 \
		rio-prettyprint-0.1.1.0 \
		safe-0.3.19 \
		safe-exceptions-0.1.7.1 \
		scientific-0.3.6.2 \
		semigroupoids-5.3.5 \
		semigroups-0.19.1 \
		silently-1.2.5.1 \
		socks-0.6.1 \
		split-0.2.3.4_1 \
		splitmix-0.1.0.3 \
		stm-chans-3.0.0.4_1 \
		streaming-commons-0.2.2.1 \
		strict-0.4.0.1 \
		syb-0.7.2.1 \
		tagged-0.8.6.1_1 \
		tar-0.5.1.1_3 \
		tar-conduit-0.3.2 \
		temporary-1.3 \
		text-metrics-0.3.0_4 \
		th-abstraction-0.4.2.0_1 \
		th-compat-0.1.2 \
		th-expand-syns-0.4.8.0 \
		th-lift-0.8.2_1 \
		th-lift-instances-0.1.18 \
		th-reify-many-0.1.9 \
		these-1.1.1.1_1 \
		time-compat-1.9.5_1 \
		tls-1.5.5 \
		transformers-base-0.4.5.2 \
		transformers-compat-0.6.6 \
		typed-process-0.2.6.0 \
		unicode-transforms-0.3.7.1_1 \
		unix-compat-0.5.3 \
		unix-time-0.4.7 \
		unliftio-0.2.16 \
		unliftio-core-0.2.0.1_1 \
		unordered-containers-0.2.13.0 \
		uuid-types-1.0.5 \
		vector-0.12.3.0 \
		vector-algorithms-0.8.0.4_1 \
		x509-1.7.5_1 \
		x509-store-1.6.7_1 \
		x509-system-1.6.6 \
		x509-validation-1.6.11 \
		yaml-0.11.5.0 \
		zip-archive-0.4.1_1 \
		zlib-0.6.2.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1300078 && ${ARCH} != powerpc64
LIB_DEPENDS+=	libncursesw.so.8:misc/compat12x
.endif

#PLIST_FILES=	etc/bash_completion.d/_stack.bash \
#		share/zsh/site-functions/_stack

.include <bsd.port.post.mk>
