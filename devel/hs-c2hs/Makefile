# New ports collection makefile for:   c2hs
# Date created:        23 August 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	c2hs
PORTVERSION=	0.11.5
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.cse.unsw.edu.au/~chak/haskell/c2hs/
PKGNAMEPREFIX=	hs-

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	C->Haskell, an Interface Generator for Haskell

BUILD_DEPENDS=	ghc-5.04.3:${PORTSDIR}/lang/ghc5
RUN_DEPENDS=	ghc-5.04.3:${PORTSDIR}/lang/ghc5

USE_SIZE=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes

GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
PLIST_SUB+=	C2HS_VERSION="${PORTVERSION}" GHC_VERSION="${GHC_VERSION}"

CONFIGURE_ARGS+=	--prefix=${PREFIX} --enable-add-package

MAN1=	c2hs-config.1 c2hs.1

post-build:
	@(cd ${WRKSRC}/doc/c2hs && ${GMAKE} man1/c2hs-config.1 man1/c2hs.1)

post-install:
	@(cd ${WRKSRC}/doc/c2hs/man1 && \
		 ${INSTALL_MAN} c2hs-config.1 c2hs.1 ${MANPREFIX}/man/man1)
	@${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
