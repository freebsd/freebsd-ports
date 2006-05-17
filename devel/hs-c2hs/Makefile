# New ports collection makefile for:   c2hs
# Date created:        23 August 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	c2hs
PORTVERSION=	0.13.6
PORTREVISION=	2
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.cse.unsw.edu.au/~chak/haskell/c2hs/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	C->Haskell, an Interface Generator for Haskell

OPTIONS=	GHC5 "Build for ghc5" off

.include <bsd.port.pre.mk>

.if defined(WITH_GHC5)
GHC=		ghc-5.04.3
GHCDEP=		ghc5
GHCMAJOR=	5
.else
GHC=		ghc-6.4.2
GHCDEP=		ghc
GHCMAJOR=	6
.endif
PKGNAMESUFFIX=	-${GHCDEP}

BUILD_DEPENDS=	${GHC}:${PORTSDIR}/lang/${GHCDEP}
RUN_DEPENDS=	${GHC}:${PORTSDIR}/lang/${GHCDEP}

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

GHC_VERSION=	${GHC:S/^ghc-//} # `${LOCALBASE}/bin/${GHC} --numeric-version`
PLIST_SUB+=	C2HS_VERSION="${PORTVERSION}" GHC_VERSION="${GHC_VERSION}"
PLIST_SUB+=	GHCMAJOR="${GHCMAJOR}"

CONFIGURE_ARGS+=	--prefix=${PREFIX} --enable-add-package \
			--with-hc=${GHC}

MAN1=	c2hs-config.1 c2hs.1

post-build:
	@(cd ${WRKSRC}/doc/c2hs && ${GMAKE} man1/c2hs-config.1 man1/c2hs.1)

post-install:
	@(cd ${WRKSRC}/doc/c2hs/man1 && \
		 ${INSTALL_MAN} c2hs-config.1 c2hs.1 ${MANPREFIX}/man/man1)
	@${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.post.mk>
