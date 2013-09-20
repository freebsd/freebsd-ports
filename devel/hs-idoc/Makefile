# Created by: Oliver Braun <obraun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	idoc
PORTVERSION=	0.2.6
PORTREVISION=	9
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.cse.unsw.edu.au/~chak/haskell/idoc/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	No Frills Haskell Interface Documentation System

LICENSE=	GPLv2

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp \
		ffi.6:${PORTSDIR}/devel/libffi

PLIST_FILES=	bin/idoc
USE_GMAKE=	yes
MAKE_ARGS=	PREFIX="${PREFIX}"

ALL_TARGET=	# empty

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|IOExts|Debug.Trace|' ${WRKSRC}/IDoc.hs

.include <bsd.port.mk>
