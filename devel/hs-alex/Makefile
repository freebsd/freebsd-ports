# New ports collection makefile for:	alex
# Date created:				29 January 2003
# Whom:					Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$

PORTNAME=	alex
PORTVERSION=	2.0
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.syntaxpolice.org/~ijones/alex/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

PKGNAMEPREFIX=	hs-

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	Alex is a Lex-like package for generating Haskell scanners

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

USE_GMAKE=	yes

BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	makefile
ALL_TARGET=	alex

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/alex ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
.for i in Alex.hs ctx.x lit.lx pp.x tiny.y xscan.x Tokens.x examples.x makefile state.x tkns.hs
	${INSTALL_DATA} ${WRKSRC}/examples/$i ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/alex.ps ${WRKSRC}/doc/alex.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
