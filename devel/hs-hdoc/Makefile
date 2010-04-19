# New ports collection makefile for:	hdoc
# Date created:				25 October 2002
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	hdoc
PORTVERSION=	0.8.3
PORTREVISION=	4
CATEGORIES=	devel haskell
MASTER_SITES=	http://staff.fmi.uni-passau.de/~groessli/hdoc/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	HTML documentation tool for Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}

PLIST_FILES=	bin/hdoc
.if !defined(NOPORTDOCS)
PLIST_DIRS=	share/doc/${DISTNAME}
PLIST_FILES+=	share/doc/${DISTNAME}/hdoc.pdf
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}
ALL_TARGET=	# empty

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} && \
	  cd ${WRKSRC}/docs && ${INSTALL_DATA} hdoc.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
