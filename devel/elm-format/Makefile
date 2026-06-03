PORTNAME=	elm-format
#DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.8
CATEGORIES=	devel textproc

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Elm source code formatter based on the official Elm Style Guide
WWW=		https://github.com/avh4/elm-format/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ghc-9.6.7:lang/ghc96

USES=		cabal
USE_GITHUB=	yes
GH_ACCOUNT=	avh4

CABAL_PROJECT=	append

post-extract:
	${RM} ${WRKSRC}/cabal.project.freeze
	${ECHO} "module Build_elm_format where" > ${WRKSRC}/src/Build_elm_format.hs
	${ECHO} "gitDescribe :: String" >> ${WRKSRC}/src/Build_elm_format.hs
	${ECHO} "gitDescribe = \"${PORTNAME}\"" >> ${WRKSRC}/src/Build_elm_format.hs

post-patch:
	@${REINPLACE_CMD} -e '/with-compiler: ghc-/d' \
		${WRKSRC}/cabal.project || ${TRUE}

.include <bsd.port.mk>
