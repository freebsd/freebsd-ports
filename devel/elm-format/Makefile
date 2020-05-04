# $FreeBSD$

PORTNAME=	elm-format
PORTVERSION=	0.8.3
PORTREVISION=	1
CATEGORIES=	devel textproc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Elm source code formatter based on the official Elm Style Guide

LICENSE=	BSD3CLAUSE

USES=		cabal

USE_GITHUB=	yes
GH_ACCOUNT=	avh4
GH_PROJECT=	elm-format

USE_CABAL=	ansi-terminal-0.8.2 \
		ansi-wl-pprint-0.6.8.2_2 \
		base-orphans-0.8.2 \
		bifunctors-5.5.7 \
		cabal-doctest-1.0.8_1 \
		colour-2.3.5 \
		comonad-5.0.6 \
		concatenative-1.0.1 \
		contravariant-1.5.2 \
		distributive-0.6.1 \
		exceptions-0.10.4_1 \
		free-5.1.3 \
		hashable-1.3.0.0_1 \
		indents-0.3.3 \
		json-0.10_1 \
		optparse-applicative-0.15.1.0_1 \
		profunctors-5.5.2 \
		semigroupoids-5.3.4 \
		split-0.2.3.4 \
		StateVar-1.2 \
		syb-0.7.1 \
		tagged-0.8.6_2 \
		th-abstraction-0.3.2.0 \
		transformers-base-0.4.5.2 \
		transformers-compat-0.6.5 \
		unordered-containers-0.2.10.0_1

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|g' \
		${WRKSRC}/src/ElmFormat/Version.hs
	${RM} ${WRKSRC}/cabal.config

.include <bsd.port.mk>
