PORTNAME=	alex
PORTVERSION=	3.2.6
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Tool for generating lexical analysers in Haskell

LICENSE=	BSD3CLAUSE

USES=		cabal

CABAL_WRAPPER_SCRIPTS=	${EXECUTABLES}

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	Makefile *.x *.y

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/* ${STAGEDIR}${DATADIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
