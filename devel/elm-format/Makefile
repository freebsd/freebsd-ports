# $FreeBSD$

PORTNAME=	elm-format
PORTVERSION=	0.8.3
CATEGORIES=	devel textproc

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Elm source code formatter based on the official Elm Style Guide

LICENSE=	BSD3CLAUSE

USES=		cabal

USE_GITHUB=	yes
GH_ACCOUNT=	avh4
GH_PROJECT=	elm-format

USE_CABAL=	ansi-terminal-0.8.2 \
		ansi-wl-pprint-0.6.8.2_2 \
		base-orphans-0.8.1 \
		bifunctors-5.5.4_1 \
		binary-0.8.7.0 \
		Cabal-2.4.1.0_1 \
		cabal-doctest-1.0.6_2 \
		colour-2.3.5 \
		comonad-5.0.5 \
		concatenative-1.0.1 \
		containers-0.6.0.1 \
		contravariant-1.5.1 \
		distributive-0.6 \
		exceptions-0.10.2 \
		free-5.1.1 \
		hashable-1.3.0.0 \
		indents-0.3.3 \
		json-0.9.3 \
		optparse-applicative-0.14.3.0_2 \
		parsec-3.1.13.0_2 \
		profunctors-5.4 \
		semigroupoids-5.3.2_1 \
		split-0.2.3.3_1 \
		StateVar-1.1.1.1 \
		syb-0.7 \
		tagged-0.8.6_1 \
		text-1.2.3.1_2 \
		th-abstraction-0.3.1.0 \
		transformers-base-0.4.5.2 \
		transformers-compat-0.6.5 \
		unordered-containers-0.2.10.0_1

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|g' \
		${WRKSRC}/src/ElmFormat/Version.hs

.include <bsd.port.mk>
