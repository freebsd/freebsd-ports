# ex:ts=8
# Ports collection makefile for:	lhs2TeX
# Date created:			April 24, 2007
# Whom:				mainland@apeiron.net
#
# $FreeBSD$
#

PORTNAME=	lhs2tex
PORTVERSION=	1.15
PORTREVISION=	2
CATEGORIES=	devel haskell
MASTER_SITES=	http://people.cs.uu.nl/andres/${PORTNAME}/

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A preprocessor to generate LaTeX code from literate Haskell sources

BUILD_DEPENDS=	ghc>=6.8:${PORTSDIR}/lang/ghc \
		mktexlsr:${PORTSDIR}/print/teTeX-base \
		hs-utf8-string>=0.3:${PORTSDIR}/devel/hs-utf8-string

RUN_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--datadir=${PREFIX}/share \
		--docdir=${DOCSDIR} \
		--mandir=${MANPREFIX}/man

DOCSDIR=${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*
DATADIR=${PREFIX}/share/${PORTNAME}-${PORTVERSION}
PORTDATA=	*

.include <bsd.port.pre.mk>

INSTALL_TARGET=	install

.if !defined(NOPORTDOCS)
INSTALL_TARGET+=	install-doc
.endif

.if !defined(NOPORTDATA)
INSTALL_TARGET+=	install-data
.endif

MAN1=		lhs2TeX.1

.include <bsd.port.post.mk>
