# New ports collection makefile for:	ghc
# Version required:			4.04
# Date created:				28 August 1999
# Whom:					Simon Marlow <simonmar@microsoft.com>
#
# $FreeBSD$

DISTNAME=	ghc-4.04
CATEGORIES=	lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/4.04/
DISTFILES=	ghc-4.04-src${EXTRACT_SUFX} ghc-4.04-x86-hc${EXTRACT_SUFX}

MAINTAINER=	simonmar@microsoft.com

USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS= --enable-hc-boot --libdir=${PREFIX}/lib/ghc

WRKSRC=		${WRKDIR}/fptools

# Note:
# 	- This port will bootstrap from pre-compiled C files.
# 	- ToDo: bootstrap using existing compiler, if one is installed.

# XXX: we touch the happy-generated files to ensure that when we
# switch to non-bootstrapping mode for installation, the build system
# won't try to create them.
#
pre-build:
	@${CP} ${FILESDIR}/build.mk ${WRKSRC}/mk
	@${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/ghc/compiler/rename/ParseIface.hs
	@${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/ghc/compiler/parser/Parser.hs
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} boot)

post-build:
	@echo "GhcWithHscBuiltViaC=NO" >>${WRKSRC}/mk/build.mk
	@(cd ${WRKSRC}/ghc/lib; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} clean boot all)

.include <bsd.port.mk>
