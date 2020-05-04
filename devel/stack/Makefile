# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	stack
PORTVERSION=	2.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel haskell
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Cross-platform program for developing Haskell programs

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	happy:devel/hs-happy
RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		gmake:devel/gmake

USE_GITHUB=	yes
GH_ACCOUNT=	commercialhaskell
GH_PROJECT=	stack

USES=		cabal gmake perl5

USE_PERL5=	run

USE_CABAL=	aeson-1.4.7.1_1 \
		annotated-wl-pprint-0.7.0_1 \
		ansi-terminal-0.10.3 \
		ansi-wl-pprint-0.6.9_1 \
		asn1-encoding-0.9.6_1 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		async-2.2.2_1 \
		attoparsec-0.13.2.4 \
		attoparsec-iso8601-1.0.1.0_1 \
		auto-update-0.1.6 \
		base-compat-0.11.1 \
		base-compat-batteries-0.11.1 \
		base-orphans-0.8.2 \
		base16-bytestring-0.1.1.6 \
		base64-bytestring-1.0.0.3 \
		basement-0.0.11_2 \
		bifunctors-5.5.7 \
		bitarray-0.0.1.1_1 \
		blaze-builder-0.4.1.0 \
		blaze-html-0.9.1.2 \
		blaze-markup-0.8.2.4 \
		cabal-doctest-1.0.8_1 \
		casa-client-0.0.1 \
		casa-types-0.0.1 \
		case-insensitive-1.2.1.0 \
		cereal-0.5.8.1 \
		clock-0.8 \
		cmdargs-0.10.20 \
		colour-2.3.5 \
		comonad-5.0.6 \
		conduit-1.3.2 \
		conduit-combinators-1.3.0 \
		conduit-extra-1.3.5 \
		connection-0.3.1_1 \
		contravariant-1.5.2 \
		cookie-0.4.5 \
		cryptohash-sha256-0.11.101.0_4 \
		cryptonite-0.26 \
		cryptonite-conduit-0.2.2_1 \
		data-default-class-0.1.2.0 \
		digest-0.0.1.2 \
		distributive-0.6.1 \
		dlist-0.8.0.8 \
		easy-file-0.2.2 \
		echo-0.1.3_1 \
		ed25519-0.0.5.0_2 \
		either-5.0.1.1_1 \
		exceptions-0.10.4_1 \
		extra-1.7.1 \
		fast-logger-3.0.1 \
		file-embed-0.0.11.2 \
		filelock-0.1.1.4 \
		fsnotify-0.3.0.1_1 \
		generic-deriving-1.13.1 \
		githash-0.1.4.0 \
		Glob-0.10.0_1 \
		hackage-security-0.6.0.0_1 \
		hashable-1.3.0.0_1 \
		hi-file-parser-0.1.0.0_2 \
		hourglass-0.2.12 \
		hpack-0.33.0 \
		hsc2hs-0.68.7 \
		http-api-data-0.4.1.1_1 \
		http-client-0.6.4.1 \
		http-client-tls-0.3.5.3_1 \
		http-conduit-2.3.7.3 \
		http-download-0.2.0.0 \
		http-types-0.12.3 \
		infer-license-0.2.0 \
		integer-logarithms-1.0.3_2 \
		libyaml-0.1.2 \
		lifted-base-0.2.3.12 \
		lukko-0.1.1.2 \
		megaparsec-8.0.0 \
		memory-0.15.0_1 \
		microlens-0.4.11.2 \
		microlens-th-0.4.3.4 \
		mime-types-0.1.0.9 \
		mintty-0.1.2 \
		monad-control-1.0.2.3 \
		monad-logger-0.3.32 \
		monad-loops-0.4.3 \
		mono-traversable-1.0.15.1 \
		mustache-2.3.1 \
		neat-interpolation-0.5.1 \
		network-3.1.1.1 \
		network-uri-2.6.3.0 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2 \
		open-browser-0.2.1.0 \
		optparse-applicative-0.15.1.0_1 \
		optparse-simple-0.1.1.2 \
		pantry-0.4.0.1 \
		parser-combinators-1.2.1 \
		path-0.7.0_1 \
		path-io-1.6.0_1 \
		path-pieces-0.2.1_1 \
		pem-0.2.4 \
		persistent-2.10.5.2 \
		persistent-sqlite-2.10.6.2 \
		persistent-template-2.8.2.3 \
		primitive-0.7.0.1 \
		profunctors-5.5.2 \
		project-template-0.2.0.1_1 \
		random-1.1_1 \
		regex-applicative-0.3.3.1 \
		regex-applicative-text-0.1.0.1_5 \
		resource-pool-0.2.3.2 \
		resourcet-1.2.3 \
		retry-0.8.1.0 \
		rio-0.1.15.0 \
		rio-orphans-0.1.1.0 \
		rio-prettyprint-0.1.0.0_2 \
		safe-0.3.18_1 \
		safe-exceptions-0.1.7.0_5 \
		scientific-0.3.6.2 \
		semigroupoids-5.3.4 \
		semigroups-0.19.1 \
		silently-1.2.5.1 \
		socks-0.6.1 \
		split-0.2.3.4 \
		StateVar-1.2 \
		stm-chans-3.0.0.4_1 \
		streaming-commons-0.2.1.2 \
		syb-0.7.1 \
		tagged-0.8.6_2 \
		tar-0.5.1.1_2 \
		tar-conduit-0.3.2 \
		temporary-1.3 \
		text-metrics-0.3.0_4 \
		th-abstraction-0.3.2.0 \
		th-expand-syns-0.4.6.0 \
		th-lift-0.8.1 \
		th-lift-instances-0.1.14 \
		th-reify-many-0.1.9 \
		time-compat-1.9.3 \
		tls-1.5.4 \
		transformers-base-0.4.5.2 \
		transformers-compat-0.6.5 \
		typed-process-0.2.6.0 \
		unicode-transforms-0.3.6 \
		unix-compat-0.5.2_1 \
		unix-time-0.4.7 \
		unliftio-0.2.12.1 \
		unliftio-core-0.2.0.1_1 \
		unordered-containers-0.2.10.0_1 \
		uuid-types-1.0.3_2 \
		vector-0.12.1.2 \
		vector-algorithms-0.8.0.3 \
		x509-1.7.5_1 \
		x509-store-1.6.7_1 \
		x509-system-1.6.6 \
		x509-validation-1.6.11 \
		yaml-0.11.3.0 \
		zip-archive-0.4.1_1 \
		zlib-0.6.2.1_1

#PLIST_FILES=	etc/bash_completion.d/_stack.bash \
#		share/zsh/site-functions/_stack

.include <bsd.port.mk>
