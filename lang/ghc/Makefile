# New ports collection makefile for:	ghc
# Date created:				28 August 1999
# Whom:					Simon Marlow <simonmar@microsoft.com>
#
# $FreeBSD$

PORTNAME=	ghc
PORTVERSION=	5.02.1
CATEGORIES=	lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/${PORTVERSION}/

SRC_DIST=	ghc-${PORTVERSION}-src-1${EXTRACT_SUFX} 
BOOT_DIST=	ghc-${PORTVERSION}-i386-unknown-freebsd-boot${EXTRACT_SUFX}

DISTFILES=	${SRC_DIST} ${BOOT_DIST}

MAINTAINER=	simonmar@microsoft.com

USE_BZIP2=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_SUB=      GHC_VERSION=${PORTVERSION}

# This port builds by downloading a minimal binary distribution of GHC and
# using that to bootstrap.
BOOT_DIR=	${WRKDIR}/ghc-${PORTVERSION}-boot
BOOT_GHC=	${BOOT_DIR}/bin/i386-unknown-freebsd/ghc-${PORTVERSION}

CONFIGURE_ARGS= --with-ghc=${BOOT_GHC}
# specifying CONFIGURE_TARGET doesn't work for some reason.
CONFIGURE_TARGET=

# override TMPDIR because /tmp often doesn't have enough space
# to build some of the larger libraries.
TMPDIR = ${WRKSRC}/tmp
MAKE_ENV += TMPDIR=${TMPDIR}

pre-configure:
	@(cd ${BOOT_DIR} && ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})
	@(cd ${BOOT_DIR} && ${MAKE} in-place)

pre-build:
	@${MKDIR} ${TMPDIR}

.include <bsd.port.mk>
