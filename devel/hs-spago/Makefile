# $FreeBSD$

PORTNAME=	spago
DISTVERSION=	0.19.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/spacchetti/purescript-docs-search/releases/download/v${PURESCRIPT_DOCS_SEARCH_VERSION}/:docs_search_app \
		https://github.com/spacchetti/purescript-docs-search/releases/download/v${PURESCRIPT_DOCS_SEARCH_VERSION}/:purescript_docs_search
DISTFILES=	docs-search-app.js:docs_search_app \
		purescript-docs-search:purescript_docs_search
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	PureScript package manager and build tool

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss

USES=		cabal

USE_GITHUB=	yes
GH_ACCOUNT=	purescript
GH_PROJECT=	spago

USE_LOCALE=	en_US.UTF-8

USE_CABAL=	Diff-0.4.0 \
		Glob-0.10.1 \
		StateVar-1.2.1 \
		adjunctions-4.4_2 \
		aeson-1.5.6.0 \
		aeson-better-errors-0.9.1.0 \
		aeson-pretty-0.8.8 \
		ansi-terminal-0.11 \
		ansi-wl-pprint-0.6.9_2 \
		asn1-encoding-0.9.6_2 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		assoc-1.0.2_1 \
		async-2.2.3 \
		async-pool-0.9.1 \
		atomic-write-0.2.0.7 \
		attoparsec-0.13.2.5_1 \
		attoparsec-iso8601-1.0.2.0 \
		auto-update-0.1.6 \
		base-compat-0.11.2 \
		base-compat-batteries-0.11.2 \
		base-orphans-0.8.4 \
		base16-bytestring-0.1.1.7_3 \
		base64-bytestring-1.2.0.1 \
		basement-0.0.11_2 \
		basic-prelude-0.7.0 \
		bifunctors-5.5.10 \
		binary-instances-1.0.1_1 \
		binary-orphans-1.0.1_5 \
		blaze-builder-0.4.2.1 \
		bower-json-1.0.0.1 \
		bytestring-conversion-0.3.1_2 \
		cabal-doctest-1.0.8_2 \
		case-insensitive-1.2.1.0 \
		cborg-0.2.4.0 \
		cborg-json-0.2.2.0_2 \
		cereal-0.5.8.1 \
		charset-0.3.8 \
		chunked-data-0.3.1 \
		classy-prelude-1.5.0 \
		clock-0.8.2 \
		colour-2.3.5 \
		comonad-5.0.8 \
		conduit-1.3.4.1 \
		conduit-extra-1.3.5 \
		connection-0.3.1_1 \
		contravariant-1.5.3 \
		cookie-0.4.5 \
		cryptohash-sha1-0.11.100.1_5 \
		cryptonite-0.28 \
		data-default-class-0.1.2.0 \
		data-fix-0.3.1 \
		deepseq-generics-0.2.0.0_5 \
		dhall-1.38.0_2 \
		distributive-0.6.2.1 \
		dlist-1.0 \
		dlist-instances-0.1.1.1 \
		dotgen-0.4.3 \
		double-conversion-2.0.2.0 \
		easy-file-0.2.2 \
		either-5.0.1.1_1 \
		errors-2.3.0 \
		fast-logger-3.0.3 \
		fgl-5.7.0.3 \
		file-embed-0.0.13.0 \
		foldl-1.4.11 \
		free-5.1.6 \
		fsnotify-0.3.0.1_1 \
		generic-lens-2.1.0.0 \
		generic-lens-core-2.1.0.0 \
		github-0.26 \
		half-0.3.1 \
		hashable-1.3.1.0 \
		hostname-1.0 \
		hourglass-0.2.12 \
		hsc2hs-0.68.7_1 \
		http-api-data-0.4.3_1 \
		http-client-0.7.6 \
		http-client-tls-0.3.5.3_1 \
		http-conduit-2.3.8 \
		http-link-header-1.0.3.1 \
		http-types-0.12.3 \
		indexed-profunctors-0.1 \
		indexed-traversable-0.1.1 \
		integer-logarithms-1.0.3.1 \
		invariant-0.5.4 \
		iso8601-time-0.1.5 \
		kan-extensions-5.2.2 \
		keys-3.12.3 \
		lens-family-core-2.1.0 \
		lifted-base-0.2.3.12 \
		managed-1.0.8 \
		math-functions-0.3.4.1 \
		megaparsec-7.0.5 \
		memory-0.15.0_1 \
		microlens-0.4.12.0 \
		microlens-mtl-0.2.0.1 \
		mime-types-0.1.0.9 \
		mmorph-1.1.5_1 \
		monad-control-1.0.2.3 \
		monad-logger-0.3.36 \
		monad-loops-0.4.3 \
		mono-traversable-1.0.15.1 \
		mono-traversable-instances-0.1.1.0 \
		mutable-containers-0.3.4 \
		mwc-random-0.15.0.1_1 \
		network-3.1.2.1_1 \
		network-uri-2.6.4.1 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2 \
		open-browser-0.2.1.0 \
		optional-args-1.0.2_1 \
		optparse-applicative-0.16.1.0 \
		parser-combinators-1.3.0 \
		parsers-0.12.10 \
		pem-0.2.4 \
		pointed-5.0.2 \
		pretty-simple-4.0.0.0 \
		prettyprinter-1.7.0 \
		prettyprinter-ansi-terminal-1.1.2 \
		primitive-0.7.1.0_2 \
		profunctors-5.6.2 \
		random-1.2.0_5 \
		repline-0.4.0.0 \
		resourcet-1.2.4.2 \
		retry-0.8.1.2 \
		rio-0.1.20.0 \
		rio-orphans-0.1.1.0 \
		safe-0.3.19 \
		safe-exceptions-0.1.7.1 \
		say-0.1.0.1 \
		scientific-0.3.6.2 \
		semigroupoids-5.3.5 \
		semigroups-0.19.1 \
		semver-range-0.2.8 \
		serialise-0.2.3.0_1 \
		socks-0.6.1 \
		split-0.2.3.4_1 \
		splitmix-0.1.0.3 \
		stm-chans-3.0.0.4_1 \
		streaming-commons-0.2.2.1 \
		strict-0.4.0.1 \
		stringsearch-0.3.6.6_1 \
		system-fileio-0.3.16.4 \
		system-filepath-0.4.14_1 \
		tagged-0.8.6.1 \
		tar-0.5.1.1_3 \
		temporary-1.3 \
		text-binary-0.2.1.1 \
		text-manipulate-0.3.0.0 \
		th-abstraction-0.4.2.0 \
		th-compat-0.1.1 \
		th-env-0.1.0.2 \
		th-lift-0.8.2 \
		th-lift-instances-0.1.18 \
		these-1.1.1.1_1 \
		time-compat-1.9.5_1 \
		tls-1.5.5 \
		transformers-base-0.4.5.2 \
		transformers-compat-0.6.6 \
		turtle-1.5.21 \
		typed-process-0.2.6.0 \
		unix-compat-0.5.3 \
		unix-time-0.4.7 \
		unliftio-0.2.14 \
		unliftio-core-0.2.0.1_1 \
		unordered-containers-0.2.13.0 \
		uri-encode-1.5.0.7_1 \
		utf8-string-1.0.2 \
		uuid-types-1.0.4 \
		vector-0.12.2.0 \
		vector-algorithms-0.8.0.4_1 \
		vector-binary-instances-0.2.5.1_2 \
		vector-instances-3.4 \
		versions-4.0.3 \
		void-0.7.3 \
		with-utf8-1.0.2.2 \
		x509-1.7.5_1 \
		x509-store-1.6.7_1 \
		x509-system-1.6.6 \
		x509-validation-1.6.11 \
		zlib-0.6.2.3

PURESCRIPT_DOCS_SEARCH_VERSION=	0.0.10

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/docs-search-app.js ${WRKSRC}/templates/
	${CP} ${DISTDIR}/${DIST_SUBDIR}/purescript-docs-search ${WRKSRC}/templates/

.include <bsd.port.mk>
