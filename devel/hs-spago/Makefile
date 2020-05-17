# $FreeBSD$

PORTNAME=	spago
DISTVERSION=	0.15.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/spacchetti/purescript-docs-search/releases/download/v${PURESCRIPT_DOCS_SEARCH_VERSION}/:docs_search_app \
		https://github.com/spacchetti/purescript-docs-search/releases/download/v${PURESCRIPT_DOCS_SEARCH_VERSION}/:purescript_docs_search
DISTFILES=	docs-search-app.js:docs_search_app \
		purescript-docs-search:purescript_docs_search
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	PureScript package manager and build tool

LICENSE=	BSD3CLAUSE

BROKEN_i386=	Crashes the compiler

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss

USES=		cabal:hpack

USE_GITHUB=	yes
GH_ACCOUNT=	purescript
GH_PROJECT=	spago

USE_LOCALE=	en_US.UTF-8

USE_CABAL=	Diff-0.4.0 \
		Glob-0.10.0_1 \
		StateVar-1.2 \
		adjunctions-4.4_2 \
		aeson-1.4.7.1_1 \
		aeson-better-errors-0.9.1.0 \
		aeson-pretty-0.8.8 \
		ansi-terminal-0.10.3 \
		ansi-wl-pprint-0.6.9_1 \
		asn1-encoding-0.9.6_1 \
		asn1-parse-0.9.5 \
		asn1-types-0.3.4 \
		async-2.2.2_1 \
		async-pool-0.9.1 \
		atomic-write-0.2.0.7 \
		attoparsec-0.13.2.4 \
		attoparsec-iso8601-1.0.1.0_1 \
		auto-update-0.1.6 \
		base-compat-0.11.1 \
		base-compat-batteries-0.11.1 \
		base-orphans-0.8.2 \
		base-prelude-1.3 \
		base16-bytestring-0.1.1.6 \
		basement-0.0.11_2 \
		basic-prelude-0.7.0 \
		bifunctors-5.5.7 \
		binary-instances-1.0.0.1 \
		binary-orphans-1.0.1_4 \
		blaze-builder-0.4.1.0 \
		bower-json-1.0.0.1 \
		bytestring-conversion-0.3.1_2 \
		cabal-doctest-1.0.8_1 \
		case-insensitive-1.2.1.0 \
		cborg-0.2.3.0 \
		cborg-json-0.2.2.0 \
		cereal-0.5.8.1 \
		charset-0.3.7.1_1 \
		chunked-data-0.3.1 \
		classy-prelude-1.5.0 \
		clock-0.8 \
		colour-2.3.5 \
		comonad-5.0.6 \
		conduit-1.3.2 \
		conduit-extra-1.3.5 \
		connection-0.3.1_1 \
		contravariant-1.5.2 \
		cookie-0.4.5 \
		cryptohash-sha1-0.11.100.1_5 \
		cryptonite-0.26 \
		data-default-class-0.1.2.0 \
		data-fix-0.2.1 \
		deepseq-generics-0.2.0.0_5 \
		dhall-1.32.0 \
		distributive-0.6.2 \
		dlist-0.8.0.8 \
		dlist-instances-0.1.1.1 \
		dotgen-0.4.2 \
		double-conversion-2.0.2.0 \
		easy-file-0.2.2 \
		either-5.0.1.1_1 \
		errors-2.3.0 \
		exceptions-0.10.4_1 \
		fast-logger-3.0.1 \
		fgl-5.7.0.2 \
		file-embed-0.0.12.0 \
		foldl-1.4.6 \
		free-5.1.3 \
		fsnotify-0.3.0.1_1 \
		github-0.25 \
		half-0.3 \
		hashable-1.3.0.0_1 \
		haskeline-0.8.0.0 \
		hostname-1.0 \
		hourglass-0.2.12 \
		hsc2hs-0.68.7 \
		http-api-data-0.4.1.1_1 \
		http-client-0.6.4.1 \
		http-client-tls-0.3.5.3_1 \
		http-conduit-2.3.7.3 \
		http-link-header-1.0.3.1 \
		http-types-0.12.3 \
		integer-logarithms-1.0.3_2 \
		invariant-0.5.3_1 \
		iso8601-time-0.1.5 \
		kan-extensions-5.2 \
		keys-3.12.3 \
		lens-family-core-2.1.0 \
		lifted-base-0.2.3.12 \
		managed-1.0.7 \
		math-functions-0.3.4.0_1 \
		megaparsec-7.0.5 \
		memory-0.15.0_1 \
		microlens-0.4.11.2 \
		mime-types-0.1.0.9 \
		monad-control-1.0.2.3 \
		monad-logger-0.3.32 \
		monad-loops-0.4.3 \
		mono-traversable-1.0.15.1 \
		mono-traversable-instances-0.1.0.0 \
		mutable-containers-0.3.4 \
		mwc-random-0.14.0.0 \
		network-3.1.1.1 \
		network-uri-2.6.3.0 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2 \
		open-browser-0.2.1.0 \
		optional-args-1.0.2_1 \
		optparse-applicative-0.15.1.0_1 \
		parser-combinators-1.2.1 \
		parsers-0.12.10 \
		pem-0.2.4 \
		pointed-5.0.1_2 \
		pretty-simple-3.2.2.0 \
		prettyprinter-1.6.1 \
		prettyprinter-ansi-terminal-1.1.1.2 \
		primitive-0.7.0.1 \
		profunctors-5.5.2 \
		random-1.1_1 \
		repline-0.3.0.0 \
		resourcet-1.2.4 \
		retry-0.8.1.2 \
		rio-0.1.15.1 \
		rio-orphans-0.1.1.0 \
		safe-0.3.18_1 \
		safe-exceptions-0.1.7.0_6 \
		say-0.1.0.1 \
		scientific-0.3.6.2 \
		semigroupoids-5.3.4 \
		semigroups-0.19.1 \
		semver-range-0.2.8 \
		serialise-0.2.3.0 \
		socks-0.6.1 \
		split-0.2.3.4 \
		stm-chans-3.0.0.4_1 \
		streaming-commons-0.2.1.2 \
		system-fileio-0.3.16.4 \
		system-filepath-0.4.14_1 \
		tagged-0.8.6_2 \
		tar-0.5.1.1_2 \
		temporary-1.3 \
		text-binary-0.2.1.1 \
		text-manipulate-0.2.0.1 \
		th-abstraction-0.3.2.0 \
		th-env-0.1.0.1 \
		th-lift-0.8.1 \
		th-lift-instances-0.1.16 \
		time-compat-1.9.3 \
		tls-1.5.4 \
		transformers-base-0.4.5.2 \
		transformers-compat-0.6.5 \
		turtle-1.5.19 \
		typed-process-0.2.6.0 \
		unix-compat-0.5.2_1 \
		unix-time-0.4.7 \
		unliftio-0.2.12.1 \
		unliftio-core-0.2.0.1_1 \
		unordered-containers-0.2.10.0_1 \
		uri-encode-1.5.0.5 \
		utf8-string-1.0.1.1_3 \
		uuid-types-1.0.3_2 \
		vector-0.12.1.2 \
		vector-algorithms-0.8.0.3 \
		vector-binary-instances-0.2.5.1_2 \
		vector-builder-0.3.8 \
		vector-instances-3.4 \
		versions-3.5.4 \
		void-0.7.3 \
		with-utf8-1.0.2.0 \
		x509-1.7.5_1 \
		x509-store-1.6.7_1 \
		x509-system-1.6.6 \
		x509-validation-1.6.11 \
		zlib-0.6.2.1_1

PURESCRIPT_DOCS_SEARCH_VERSION=	0.0.8

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/docs-search-app.js ${WRKSRC}/templates/
	${CP} ${DISTDIR}/${DIST_SUBDIR}/purescript-docs-search ${WRKSRC}/templates/

.include <bsd.port.mk>
