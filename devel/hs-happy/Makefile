PORTNAME=	happy
PORTVERSION=	1.20.1.1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Parser generator for Haskell
WWW=		https://www.haskell.org/happy/

LICENSE=	BSD3CLAUSE

USES=		cabal

CABAL_WRAPPER_SCRIPTS=	${CABAL_EXECUTABLES}

PORTEXAMPLES=	*.ly README glr/* igloo/*

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} $$(find ${WRKSRC} -name 'HappyTemplate*') ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
