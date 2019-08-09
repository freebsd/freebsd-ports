# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	stack
PORTVERSION=	2.1.3.1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Cross-platform program for developing Haskell programs

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	happy:devel/hs-happy
RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		gmake:devel/gmake

USES=		cabal gmake perl5

USE_PERL5=	run

USE_CABAL=	Glob-0.10.0_1 \
		StateVar-1.2 \
		aeson-1.4.4.0 \
		annotated-wl-pprint-0.7.0_1 \
		ansi-terminal-0.9.1 \
		ansi-wl-pprint-0.6.9 \
		asn1-encoding-0.9.5 \
		asn1-parse-0.9.4 \
		asn1-types-0.3.3 \
		async-2.2.2 \
		attoparsec-0.13.2.2_3 \
		attoparsec-iso8601-1.0.1.0 \
		auto-update-0.1.6 \
		base-compat-0.10.5 \
		base-orphans-0.8.1 \
		base-prelude-1.3 \
		base16-bytestring-0.1.1.6 \
		base64-bytestring-1.0.0.2 \
		basement-0.0.11 \
		bifunctors-5.5.4_1 \
		bitarray-0.0.1.1_1 \
		blaze-builder-0.4.1.0 \
		blaze-html-0.9.1.1 \
		blaze-markup-0.8.2.2_1 \
		cabal-doctest-1.0.6_2 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.1 \
		clock-0.8 \
		cmdargs-0.10.20 \
		colour-2.3.5 \
		comonad-5.0.5 \
		conduit-1.3.1.1 \
		conduit-combinators-1.3.0 \
		conduit-extra-1.3.4 \
		connection-0.3.0_1 \
		contravariant-1.5.2 \
		cookie-0.4.4 \
		cryptohash-sha256-0.11.101.0_2 \
		cryptonite-0.26 \
		cryptonite-conduit-0.2.2_1 \
		data-default-class-0.1.2.0 \
		digest-0.0.1.2 \
		distributive-0.6 \
		dlist-0.8.0.7 \
		easy-file-0.2.2 \
		echo-0.1.3_1 \
		ed25519-0.0.5.0_2 \
		either-5.0.1.1 \
		exceptions-0.10.2 \
		extra-1.6.17 \
		fast-logger-2.4.16 \
		file-embed-0.0.11 \
		filelock-0.1.1.3 \
		fsnotify-0.3.0.1_1 \
		generic-deriving-1.12.4_1 \
		githash-0.1.3.1 \
		hackage-security-0.5.3.0_6 \
		hashable-1.2.7.0_1 \
		hi-file-parser-0.1.0.0_2 \
		hourglass-0.2.12 \
		hpack-0.31.2 \
		hsc2hs-0.68.4 \
		http-api-data-0.4.1 \
		http-client-0.6.4 \
		http-client-tls-0.3.5.3_1 \
		http-conduit-2.3.7.1_1 \
		http-download-0.1.0.0_4 \
		http-types-0.12.3 \
		infer-license-0.2.0 \
		integer-logarithms-1.0.3_1 \
		libyaml-0.1.1.0 \
		lifted-base-0.2.3.12 \
		megaparsec-7.0.5 \
		memory-0.14.18_1 \
		microlens-0.4.11.2 \
		microlens-th-0.4.3.2 \
		mime-types-0.1.0.9 \
		mintty-0.1.2 \
		monad-control-1.0.2.3 \
		monad-logger-0.3.30 \
		monad-loops-0.4.3 \
		mono-traversable-1.0.11.0 \
		mustache-2.3.0 \
		neat-interpolation-0.3.2.4 \
		network-3.1.0.1 \
		network-uri-2.6.1.0_1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2 \
		open-browser-0.2.1.0 \
		optparse-applicative-0.15.0.0 \
		optparse-simple-0.1.1.2 \
		pantry-0.1.1.1 \
		parser-combinators-1.2.0 \
		path-0.6.1_1 \
		path-io-1.4.2 \
		path-pieces-0.2.1_1 \
		pem-0.2.4 \
		persistent-2.10.1 \
		persistent-sqlite-2.10.4 \
		persistent-template-2.7.2 \
		primitive-0.7.0.0 \
		profunctors-5.4 \
		project-template-0.2.0.1_1 \
		random-1.1_1 \
		regex-applicative-0.3.3 \
		regex-applicative-text-0.1.0.1_3 \
		resource-pool-0.2.3.2 \
		resourcet-1.2.2 \
		retry-0.8.0.1 \
		rio-0.1.11.0 \
		rio-orphans-0.1.1.0 \
		rio-prettyprint-0.1.0.0_2 \
		safe-0.3.17 \
		safe-exceptions-0.1.7.0_4 \
		scientific-0.3.6.2 \
		semigroupoids-5.3.2_1 \
		semigroups-0.19 \
		silently-1.2.5.1 \
		socks-0.6.0 \
		split-0.2.3.3_1 \
		stm-chans-3.0.0.4_1 \
		streaming-commons-0.2.1.1 \
		syb-0.7.1 \
		tagged-0.8.6_1 \
		tar-0.5.1.0_1 \
		tar-conduit-0.3.2 \
		temporary-1.3 \
		terminal-size-0.3.2.1 \
		text-metrics-0.3.0_4 \
		th-abstraction-0.3.1.0 \
		th-expand-syns-0.4.4.0_1 \
		th-lift-0.8.0.1 \
		th-lift-instances-0.1.13 \
		th-orphans-0.13.7_1 \
		th-reify-many-0.1.9 \
		th-utilities-0.2.3.0 \
		time-compat-1.9.2.2_1 \
		tls-1.5.1 \
		transformers-base-0.4.5.2 \
		transformers-compat-0.6.5 \
		typed-process-0.2.6.0 \
		unicode-transforms-0.3.6 \
		unix-compat-0.5.1_1 \
		unix-time-0.4.7 \
		unliftio-0.2.12 \
		unliftio-core-0.1.2.0_2 \
		unordered-containers-0.2.10.0_1 \
		uuid-types-1.0.3_2 \
		vector-0.12.0.3_2 \
		vector-algorithms-0.8.0.1_2 \
		x509-1.7.5_1 \
		x509-store-1.6.7_1 \
		x509-system-1.6.6 \
		x509-validation-1.6.11 \
		yaml-0.11.1.0 \
		zip-archive-0.4.1_1 \
		zlib-0.6.2

#PLIST_FILES=	etc/bash_completion.d/_stack.bash \
#		share/zsh/site-functions/_stack

.include <bsd.port.mk>
