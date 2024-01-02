PORTNAME=	koka
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.0
CATEGORIES=	lang haskell

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Koka: strongly typed functional-style language with effect inference
WWW=		https://koka-lang.github.io/koka/doc/index.html

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cabal

USE_GITHUB=	yes
GH_ACCOUNT=	koka-lang
GH_TUPLE=	microsoft:mimalloc:10efe29:mimalloc/kklib/mimalloc

CABAL_FLAGS=	-relocatable

USE_CABAL=	Diff-0.5_1 \
		OneTuple-0.4.1.1_1 \
		QuickCheck-2.14.3 \
		StateVar-1.2.2 \
		adjunctions-4.4.2_2 \
		aeson-2.2.1.0_1 \
		alex-3.5.0.0 \
		assoc-1.1_1 \
		async-2.2.5 \
		attoparsec-0.14.4_5 \
		base-compat-0.13.1 \
		base-compat-batteries-0.13.1 \
		base-orphans-0.9.1 \
		basement-0.0.16 \
		bifunctors-5.6.1_2 \
		boring-0.2.1_1 \
		call-stack-0.4.0 \
		cereal-0.5.8.3 \
		co-log-core-0.3.2.1 \
		comonad-5.0.8_2 \
		constraints-0.14 \
		contravariant-1.5.5 \
		cryptohash-md5-0.11.101.0_3 \
		cryptohash-sha1-0.11.101.0_3 \
		data-default-0.7.1.1 \
		data-default-class-0.1.2.0 \
		data-default-instances-containers-0.0.1 \
		data-default-instances-dlist-0.0.1 \
		data-default-instances-old-locale-0.0.1 \
		data-fix-0.3.2_5 \
		distributive-0.6.2.1_1 \
		dlist-1.0_1 \
		entropy-0.4.1.10_1 \
		file-embed-0.0.15.0 \
		foldable1-classes-compat-0.1_4 \
		free-5.2_3 \
		generic-lens-2.2.2.0_1 \
		generic-lens-core-2.2.1.0_2 \
		generically-0.1.1_2 \
		hashable-1.4.3.0_1 \
		hsc2hs-0.68.10_1 \
		indexed-profunctors-0.1.1.1 \
		indexed-traversable-0.1.3 \
		indexed-traversable-instances-0.1.1.2_2 \
		integer-conversion-0.1.0.1_1 \
		integer-logarithms-1.0.3.1_5 \
		invariant-0.6.2_1 \
		isocline-1.0.9 \
		kan-extensions-5.2.5_2 \
		lens-5.2.3_2 \
		lens-aeson-1.2.3_2 \
		lsp-2.3.0.0_1 \
		lsp-types-2.1.0.0 \
		mod-0.2.0.1 \
		network-3.1.4.0_1 \
		network-bsd-2.8.1.0_5 \
		network-info-0.2.1 \
		network-simple-0.4.5 \
		network-uri-2.6.4.2_1 \
		old-locale-1.0.0.7_2 \
		parallel-3.2.2.0_7 \
		prettyprinter-1.7.1 \
		primitive-0.9.0.0 \
		profunctors-5.6.2_3 \
		random-1.2.1.1_1 \
		reflection-2.1.7_1 \
		regex-1.1.0.2 \
		regex-base-0.94.0.2_4 \
		regex-pcre-builtin-0.95.2.3.8.44_6 \
		regex-tdfa-1.3.2.2_2 \
		row-types-1.0.1.2_1 \
		safe-0.3.19 \
		safe-exceptions-0.1.7.4_1 \
		scientific-0.3.7.0_7 \
		semialign-1.3_1 \
		semigroupoids-6.0.0.1_1 \
		semigroups-0.20 \
		semirings-0.6_1 \
		socks-0.6.1 \
		some-1.0.6 \
		sorted-list-0.2.2.0 \
		splitmix-0.1.0.5 \
		strict-0.5_1 \
		tagged-0.8.8 \
		text-iso8601-0.1_1 \
		text-rope-0.2 \
		text-short-0.1.5_3 \
		th-abstraction-0.6.0.0_1 \
		th-compat-0.1.4_3 \
		these-1.2_1 \
		time-compat-1.9.6.1_6 \
		time-locale-compat-0.1.1.5 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		type-equality-1_6 \
		unliftio-core-0.2.1.0_3 \
		unordered-containers-0.2.19.1_3 \
		utf8-string-1.0.2 \
		uuid-1.3.15_3 \
		uuid-types-1.0.5.1 \
		vector-0.13.1.0 \
		vector-stream-0.1.0.0_3 \
		void-0.7.3 \
		witherable-0.4.2_4

CABAL_EXECUTABLES=	${PORTNAME}
CABAL_WRAPPER_SCRIPTS=	${CABAL_EXECUTABLES}

post-install:
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} lib ${STAGEDIR}${PREFIX}/libexec/cabal/share/koka/${DISTVERSIONFULL} && \
		${COPYTREE_SHARE} kklib ${STAGEDIR}${PREFIX}/libexec/cabal/share/koka/${DISTVERSIONFULL}

.include <bsd.port.mk>
