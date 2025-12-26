PORTNAME=	ormolu
DISTVERSION=	0.8.0.2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Formatter for Haskell source code
WWW=		https://github.com/tweag/ormolu/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cabal

USE_LOCALE=	C.UTF-8

USE_CABAL=	Cabal-syntax-3.14.2.0 \
		Diff-1.0.2 \
		MemoTrie-0.6.11 \
		alex-3.5.4.0 \
		ansi-terminal-1.1.5 \
		ansi-terminal-types-1.1.3 \
		async-2.2.5_3 \
		case-insensitive-1.2.1.0 \
		choice-0.2.4.1 \
		colour-2.3.6 \
		file-embed-0.0.16.0 \
		ghc-lib-parser-9.12.2.20250421 \
		happy-2.1.7 \
		happy-lib-2.1.7 \
		hashable-1.5.0.0_1 \
		integer-logarithms-1.0.4 \
		megaparsec-9.7.0 \
		newtype-generics-0.6.2_5 \
		optparse-applicative-0.18.1.0_1 \
		parser-combinators-1.3.0_1 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.1.0 \
		safe-exceptions-0.1.7.4_1 \
		scientific-0.3.8.0_2 \
		syb-0.7.3 \
		th-compat-0.1.6 \
		th-env-0.1.1 \
		transformers-compat-0.7.2 \
		unliftio-0.2.25.1 \
		unliftio-core-0.2.1.0_4

post-patch:
	${REINPLACE_CMD} 's|jobs: 1|jobs: 2|' ${CABAL_HOME}/.cabal/config

.include <bsd.port.mk>
