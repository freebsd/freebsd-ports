PORTNAME=	hls-install
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Helper for building devel/hs-haskell-language-server

LICENSE=	APACHE20

USES=		cabal

USE_GITHUB=	yes
GH_ACCOUNT=	haskell
GH_PROJECT=	haskell-language-server

USE_CABAL=	Cabal-3.4.0.0 \
		aeson-1.5.6.0_1 \
		assoc-1.0.2_1 \
		attoparsec-0.14.1 \
		base-compat-0.11.2 \
		base-compat-batteries-0.11.2 \
		base-orphans-0.8.4 \
		base16-bytestring-1.0.1.0 \
		bifunctors-5.5.10 \
		binary-instances-1.0.1_1 \
		binary-orphans-1.0.1_5 \
		cabal-install-parsers-0.4.1_1 \
		case-insensitive-1.2.1.0 \
		clock-0.8.2 \
		comonad-5.0.8 \
		cryptohash-sha256-0.11.102.0 \
		data-fix-0.3.1 \
		distributive-0.6.2.1 \
		dlist-1.0 \
		extra-1.7.9 \
		filepattern-0.1.2 \
		hashable-1.3.1.0 \
		heaps-0.4 \
		hsc2hs-0.68.7_1 \
		indexed-traversable-0.1.1 \
		integer-logarithms-1.0.3.1 \
		js-dgtable-0.5.2 \
		js-flot-0.8.3 \
		js-jquery-3.3.1 \
		lukko-0.1.1.3_1 \
		network-uri-2.6.4.1 \
		primitive-0.7.1.0_2 \
		random-1.2.0_5 \
		scientific-0.3.6.2 \
		shake-0.19.4 \
		splitmix-0.1.0.3 \
		strict-0.4.0.1 \
		tagged-0.8.6.1 \
		tar-0.5.1.1_3 \
		text-binary-0.2.1.1 \
		th-abstraction-0.4.2.0 \
		th-compat-0.1.2 \
		these-1.1.1.1_1 \
		time-compat-1.9.5_1 \
		transformers-compat-0.6.6 \
		unordered-containers-0.2.13.0 \
		utf8-string-1.0.2 \
		uuid-types-1.0.4 \
		vector-0.12.3.0 \
		vector-binary-instances-0.2.5.2

CABAL_PROJECT=	remove

WRKSRC_SUBDIR=	install
NOT_FOR_ARCHS=	i386

post-extract:
	echo "executable hls-install" >> ${WRKSRC}/hls-install.cabal
	echo "  main-is: ../install.hs" >> ${WRKSRC}/hls-install.cabal
	echo "  build-depends: hls-install"  >> ${WRKSRC}/hls-install.cabal
	echo "               , base"  >> ${WRKSRC}/hls-install.cabal

.include <bsd.port.mk>
