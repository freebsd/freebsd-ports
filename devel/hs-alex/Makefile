PORTNAME=	alex
DISTVERSION=	3.5.4.0
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Tool for generating lexical analysers in Haskell
WWW=		https://www.haskell.org/alex/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cabal

CABAL_WRAPPER_SCRIPTS=	${CABAL_EXECUTABLES}

PORTEXAMPLES=	examples/*

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|ALEX=../dist/build/alex/alex|ALEX=${PREFIX}/bin/alex|' \
		-e 's|--template=..||g' \
		${WRKSRC}/examples/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/* ${STAGEDIR}${DATADIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
