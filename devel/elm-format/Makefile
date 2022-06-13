PORTNAME=	elm-format
PORTVERSION=	0.8.5
CATEGORIES=	devel textproc

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Elm source code formatter based on the official Elm Style Guide

LICENSE=	BSD3CLAUSE

USES=		cabal
USE_GITHUB=	yes
GH_ACCOUNT=	avh4

USE_CABAL=	HUnit-1.6.2.0 \
		QuickCheck-2.14.2 \
		ansi-terminal-0.10.3 \
		ansi-wl-pprint-0.6.9_3 \
		bimap-0.3.3 \
		call-stack-0.4.0 \
		clock-0.8.3 \
		colour-2.3.6 \
		concatenative-1.0.1 \
		hashable-1.4.0.2 \
		hspec-2.10.0 \
		hspec-core-2.10.0 \
		hspec-discover-2.10.0 \
		hspec-expectations-0.8.2 \
		hspec-golden-0.2.0.0 \
		indents-0.3.3 \
		json-0.10_1 \
		logict-0.8.0.0 \
		optparse-applicative-0.15.1.0_1 \
		primitive-0.7.4.0 \
		quickcheck-io-0.2.0 \
		random-1.2.1.1 \
		relude-1.1.0.0 \
		setenv-0.1.1.3_1 \
		smallcheck-1.2.1_1 \
		split-0.2.3.4_2 \
		splitmix-0.1.0.4 \
		syb-0.7.2.1 \
		tagged-0.8.6.1_2 \
		tasty-1.4.2.3 \
		tasty-hspec-1.2.0.1 \
		tasty-hunit-0.10.0.3 \
		tasty-quickcheck-0.10.2 \
		tasty-smallcheck-0.8.2_1 \
		tf-random-0.5 \
		transformers-compat-0.6.6 \
		unbounded-delays-0.1.1.1 \
		unordered-containers-0.2.19.1 \
		wcwidth-0.0.2

CABAL_PROJECT=	append

post-extract:
	${RM} ${WRKSRC}/cabal.project.freeze
	${ECHO} "module Build_elm_format where" > ${WRKSRC}/src/Build_elm_format.hs
	${ECHO} "gitDescribe :: String" >> ${WRKSRC}/src/Build_elm_format.hs
	${ECHO} "gitDescribe = \"${PORTNAME}\"" >> ${WRKSRC}/src/Build_elm_format.hs

post-patch:
	@${REINPLACE_CMD} -e '/with-compiler: ghc-8.10.4/d' \
		${WRKSRC}/cabal.project.${PORTNAME}
	${RM} ${WRKSRC}/cabal.config

.include <bsd.port.mk>
