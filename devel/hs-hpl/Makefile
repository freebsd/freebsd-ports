# New ports collection makefile for:   hpl
# Date created:        23 August 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hpl
PORTVERSION=	0.4.3.2
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/ports/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
DISTNAME=	${HSPORTNAME}-${PORTVERSION}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell Ports Library provides ports in Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS=    gmp.7:${PORTSDIR}/math/libgmp4

BROKEN=		Does not build with current ghc

.include <bsd.port.pre.mk>

GHC_VERSION=	6.6.1
HSPORTNAME=	ports

# 'owned' by lang/ghc:
CABALDIR=	${PREFIX}/lib/ghc-${GHC_VERSION}/cabal
CABALCMD=	${LOCALBASE}/bin/runghc Setup.lhs

PLIST_SUB=	PORTVERSION="${PORTVERSION}" \
		HSPORTNAME="${HSPORTNAME}" \
		GHC_VERSION="${GHC_VERSION}" \
		SUBDIR=lib/ghc-${GHC_VERSION}/cabal

CONFIGURE_ARGS= --ghc --prefix=${PREFIX} --libdir=${CABALDIR} \
		--libsubdir='' --datasubdir=''

do-patch:	# current version has broken delimiters in strings here:
		${REINPLACE_CMD} -e 's/\\\([oNS]\)/\1/' ${WRKSRC}/Control/Concurrent/PortsVersion.hs

do-configure:
	cd ${WRKSRC} && ${CABALCMD} configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${CABALCMD} build \
	 && ${CABALCMD} --gen-script register

do-install:
	cd ${WRKSRC} && ${CABALCMD} install \
	 && ${INSTALL_SCRIPT} ${WRKSRC}/register.sh ${CABALDIR}/${HSPORTNAME}-register.sh

post-install:
	@${RMDIR} ${CABALDIR}/include	# empty

.include <bsd.port.post.mk>
