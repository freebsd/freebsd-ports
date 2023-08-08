PORTNAME=	hedgewars
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.hedgewars.org/download/releases/
PKGNAMESUFFIX=	-server
DISTNAME=	${PORTNAME}-src-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Server part of free Worms-like turn based strategy game
WWW=		https://www.hedgewars.org

LICENSE=	GPLv2

BUILD_DEPENDS=	ghc-8.10.7:lang/ghc810

USES=		cabal:nodefault tar:bzip2

WRKSRC_SUBDIR=	gameServer

USE_CABAL=	ConfigFile-1.1.4_1 \
		MissingH-1.6.0.0 \
		OneTuple-0.3.1_3 \
		QuickCheck-2.14.2 \
		SHA-1.6.4.4 \
		StateVar-1.2.2 \
		aeson-2.1.2.1_1 \
		assoc-1.0.2_3 \
		attoparsec-0.14.4_3 \
		base-compat-0.12.2 \
		base-compat-batteries-0.12.2 \
		base-orphans-0.8.8.2 \
		bifunctors-5.5.15 \
		bitvec-1.1.3.0 \
		comonad-5.0.8_1 \
		conduit-1.3.4.3_1 \
		contravariant-1.5.5 \
		data-array-byte-0.1.0.1_1 \
		data-fix-0.3.2_3 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		entropy-0.4.1.10 \
		generically-0.1.1 \
		hashable-1.4.2.0 \
		hsc2hs-0.68.9 \
		hslogger-1.3.1.0_6 \
		indexed-traversable-0.1.2_2 \
		indexed-traversable-instances-0.1.1.2 \
		integer-logarithms-1.0.3.1_4 \
		libyaml-0.1.2_1 \
		mono-traversable-1.0.15.3 \
		network-3.1.2.8 \
		network-bsd-2.8.1.0_4 \
		old-locale-1.0.0.7_2 \
		old-time-1.1.0.3_2 \
		primitive-0.8.0.0 \
		random-1.2.1.1 \
		regex-base-0.94.0.2_1 \
		regex-compat-0.95.2.1_2 \
		regex-posix-0.96.0.1_1 \
		regex-tdfa-1.3.2 \
		resourcet-1.3.0 \
		sandi-0.5_1 \
		scientific-0.3.7.0_4 \
		semialign-1.2.0.1_3 \
		semigroupoids-5.3.7_1 \
		split-0.2.3.5 \
		splitmix-0.1.0.4_2 \
		strict-0.4.0.1_4 \
		tagged-0.8.7 \
		text-short-0.1.5_1 \
		th-abstraction-0.5.0.0 \
		these-1.1.1.1_6 \
		time-compat-1.9.6.1_4 \
		transformers-compat-0.7.2 \
		unliftio-core-0.2.1.0_1 \
		unordered-containers-0.2.19.1_1 \
		utf8-string-1.0.2 \
		uuid-types-1.0.5_3 \
		vector-0.13.0.0_3 \
		vector-algorithms-0.9.0.1_2 \
		vector-stream-0.1.0.0_2 \
		witherable-0.4.2_4 \
		yaml-0.11.11.0 \
		zlib-0.6.3.0_1

CABAL_EXECUTABLES=	hedgewars-server checker

.include <bsd.port.mk>
