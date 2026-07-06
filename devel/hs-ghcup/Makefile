PORTNAME=	ghcup
DISTVERSION=	0.2.6.2
CATEGORIES=	devel haskell

MAINTAINER=	tiga@FreeBSD.org
COMMENT=	GHC toolchain installer
WWW=		https://github.com/haskell/ghcup-hs

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		liblz4.so:archivers/liblz4 \
		libyaml.so:textproc/libyaml \
		libzstd.so:archivers/zstd

USES=		cabal iconv libarchive pkgconfig

USE_CABAL=	Cabal-3.16.1.0_1 \
		Cabal-syntax-3.16.1.0_2 \
		OneTuple-0.4.3 \
		QuickCheck-2.18.0.0 \
		StateVar-1.2.2 \
		aeson-2.2.5.0 \
		aeson-pretty-0.8.10 \
		alex-3.5.4.2 \
		ansi-terminal-1.1.5 \
		ansi-terminal-types-1.1.3 \
		assoc-1.1.1_2 \
		async-2.2.6 \
		attoparsec-0.14.4_6 \
		base-compat-0.15.0 \
		base-orphans-0.9.4 \
		base16-bytestring-1.0.2.0_1 \
		bifunctors-5.6.3_1 \
		bitvec-1.1.6.0 \
		blaze-builder-0.4.4.1 \
		bz2-1.0.1.2 \
		c2hs-0.28.8_3 \
		case-insensitive-1.2.1.0 \
		casing-0.1.4.1_1 \
		character-ps-0.1 \
		chs-cabal-1.0.0.0 \
		chs-deps-0.1.0.1 \
		clock-0.8.4 \
		colour-2.3.7 \
		comonad-5.0.10 \
		composition-prelude-3.0.1.0 \
		conduit-1.3.6.1 \
		conduit-extra-1.3.8_1 \
		contravariant-1.5.6 \
		cpphs-1.20.10 \
		cryptohash-sha256-0.11.102.1_6 \
		data-fix-0.3.4_2 \
		disk-free-space-0.1.0.1_3 \
		distributive-0.6.3 \
		dlist-1.0_2 \
		extra-1.8.1 \
		file-uri-0.1.0.0_3 \
		filepattern-0.1.3 \
		free-5.2_8 \
		fusion-plugin-types-0.1.0 \
		happy-2.2 \
		happy-lib-2.2 \
		hashable-1.5.1.0 \
		heaps-0.4.1 \
		hsc2hs-0.68.10_5 \
		indexed-profunctors-0.1.1.1 \
		indexed-traversable-0.1.5 \
		indexed-traversable-instances-0.1.2.1 \
		integer-conversion-0.1.1_2 \
		integer-logarithms-1.0.5 \
		language-c-0.10.2 \
		libarchive-3.0.5.0 \
		libyaml-streamly-0.2.4.0_1 \
		megaparsec-9.7.1 \
		monad-control-1.0.3.1 \
		mono-traversable-1.0.21.0 \
		mtl-compat-0.2.2 \
		network-3.2.8.0 \
		network-uri-2.6.4.2_1 \
		optics-0.4.2.1_3 \
		optics-core-0.4.2 \
		optics-extra-0.4.2.1_5 \
		optics-th-0.4.1_11 \
		optparse-applicative-0.19.0.0 \
		os-release-1.0.2.1 \
		parser-combinators-1.3.1 \
		polyparse-1.13.1 \
		pretty-terminal-0.1.0.0_1 \
		prettyprinter-1.7.2 \
		prettyprinter-ansi-terminal-1.1.4 \
		primitive-0.9.1.0_1 \
		profunctors-5.6.3 \
		random-1.3.1 \
		recursion-schemes-5.2.3_2 \
		regex-base-0.94.0.3 \
		regex-posix-0.96.0.2 \
		resourcet-1.3.0 \
		retry-0.9.3.1 \
		safe-0.3.21_1 \
		safe-exceptions-0.1.7.4_1 \
		scientific-0.3.8.1 \
		semialign-1.4 \
		semigroupoids-6.0.2_1 \
		split-0.2.5 \
		splitmix-0.1.3.2 \
		streaming-commons-0.2.3.1 \
		streamly-core-0.3.0_1 \
		strict-0.5.1_1 \
		strict-base-0.4.0.0_1 \
		tagged-0.8.10_1 \
		tagsoup-0.14.8 \
		tasty-1.5.4 \
		temporary-1.3 \
		terminal-size-0.3.4_1 \
		text-iso8601-0.1.1.1 \
		text-short-0.1.6.1 \
		th-abstraction-0.7.2.0 \
		th-compat-0.1.7 \
		th-lift-0.8.7 \
		th-lift-instances-0.1.20 \
		these-1.2.1_3 \
		time-compat-1.9.9_1 \
		transformers-base-0.4.6.1 \
		transformers-compat-0.7.2 \
		typed-process-0.2.13.0 \
		unix-bytestring-0.4.0.4 \
		unix-compat-0.7.4.1 \
		unliftio-core-0.2.1.0_4 \
		unordered-containers-0.2.21_2 \
		uri-bytestring-0.4.0.1 \
		utf8-string-1.0.2 \
		uuid-types-1.0.6.1 \
		variant-1.0.3 \
		vector-0.13.2.0_2 \
		vector-algorithms-0.9.1.0_1 \
		vector-stream-0.1.0.1_4 \
		versions-6.0.8 \
		witherable-0.5_2 \
		word8-0.1.3 \
		xz-5.6.3_3 \
		yaml-streamly-0.12.5_1 \
		zlib-0.7.1.1

CABAL_FLAGS=	-internal-downloader -tar +yaml-streamly
CABAL_PROJECT=	remove

OPTIONS_DEFINE=		DHALL TUI
OPTIONS_DEFAULT=	DHALL TUI

DHALL_DESC=	Add support for dhall encoded metadata
TUI_DESC=	Build the brick powered tui (ghcup tui)

DHALL_USE_CABAL=	Diff-1.0.2 \
			atomic-write-0.2.1.1 \
			base64-bytestring-1.2.1.0_1 \
			cborg-0.2.10.0_3 \
			cborg-json-0.2.6.0_4 \
			charset-0.3.12 \
			dhall-1.42.3 \
			dotgen-0.4.3 \
			either-5.0.3_2 \
			half-0.3.3_2 \
			microlens-0.4.14.0 \
			microlens-mtl-0.2.1.0 \
			mmorph-1.2.2_2 \
			parsers-0.12.12_1 \
			pretty-simple-4.1.4.0 \
			repline-0.4.3.0 \
			serialise-0.2.6.1_5 \
			text-manipulate-0.3.1.0
DHALL_CABAL_FLAGS=	dhall

TUI_USE_CABAL=	bimap-0.5.0 \
		brick-2.12 \
		config-ini-0.2.7.0_1 \
		data-clist-0.2_1 \
		microlens-0.4.14.0 \
		microlens-mtl-0.2.1.0 \
		microlens-th-0.4.3.17_1 \
		text-zipper-0.13 \
		vty-6.4_2 \
		vty-crossplatform-0.5.0.0 \
		vty-unix-0.2.0.0 \
		word-wrap-0.5
TUI_CABAL_FLAGS=	tui

# make sure to build against system libs
# disable stuff that's also disabled in cabal.project.release
BUILD_ARGS+=	--constraint='libyaml-streamly +system-libyaml' \
		--constraint='libyaml +system-libyaml' \
		--constraint='xz +system-xz' \
		--constraint='zlib -bundled-c-zlib' \
		--constraint='zip -disable-zstd' \
		--constraint='bzlib-conduit +system-bzip2' \
		--constraint='http-io-streams -brotli' \
		--constraint='libarchive +system-libarchive' \
		--constraint='aeson-pretty +lib-only' \
		--constraint='aeson +ordered-keymap' \
		--constraint='dhall -cross -with-http -network-tests'

.include <bsd.port.mk>
