# ex:ts=8
# Ports collection makefile for:	lhs2TeX
# Date created:			April 24, 2007
# Whom:				mainland@apeiron.net
#
# $FreeBSD$
#

PORTNAME=	lhs2tex
PORTVERSION=	1.13
CATEGORIES=	devel haskell
MASTER_SITES=	http://people.cs.uu.nl/andres/${PORTNAME}/

MAINTAINER=	mainland@apeiron.net
COMMENT=	A preprocessor to generate LaTeX code from literate Haskell sources

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		mktexlsr:${PORTSDIR}/print/teTeX-base

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--datadir=${DATADIR} \
		--docdir=${DOCSDIR} \
		--mandir=${MANPREFIX}/man

.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS)
INSTALL_TARGET=install
.else
INSTALL_TARGET=install install-doc
.endif

MAN1=		lhs2TeX.1

.if ${OSVERSION} < 700042
IGNORE=		has a broken dependency
.endif

.include <bsd.port.post.mk>
