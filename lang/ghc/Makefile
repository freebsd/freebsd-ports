# New ports collection makefile for:	ghc
# Date created:				28 August 1999
# Whom:					Simon Marlow <simonmar@microsoft.com>
#
# $FreeBSD$

PORTNAME=	ghc
PORTVERSION=	4.08.2
CATEGORIES=	lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/${PORTVERSION}/
DISTFILES=	ghc-${PORTVERSION}-src${EXTRACT_SUFX} \
		ghc-${PORTVERSION}-x86-hc${EXTRACT_SUFX}

MAINTAINER=	simonmar@microsoft.com

USE_BZIP2=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS= --enable-hc-boot --libdir=${PREFIX}/lib/ghc
# specifying CONFIGURE_TARGET doesn't work for some reason.
CONFIGURE_TARGET=

# override TMPDIR because /tmp often doesn't have enough space
# to build some of the larger libraries.
TMPDIR = ${WRKSRC}/tmp
MAKE_ENV += TMPDIR=${TMPDIR}


# Note:
# 	- This port will bootstrap from pre-compiled C files.
# 	- ToDo: bootstrap using existing compiler, if one is installed.

# XXX: we touch the happy-generated files to ensure that when we
# switch to non-bootstrapping mode for installation, the build system
# won't try to create them.
#
BOOT_COOKIE = ${WRKDIR}/.boot_done

${BOOT_COOKIE}:
	@${MKDIR} ${TMPDIR}
	@${CP} ${FILESDIR}/build.mk ${WRKSRC}/mk
	@${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/ghc/compiler/rename/ParseIface.hs
	@${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/ghc/compiler/parser/Parser.hs
	@(cd ${WRKSRC}/glafp-utils; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} boot)
	@(cd ${WRKSRC}/ghc; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} boot)
	@(cd ${WRKSRC}/hslibs; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} boot)
	@${TOUCH} ${TOUCH_FLAGS} ${BOOT_COOKIE}

pre-build: ${BOOT_COOKIE}

# After building the compiler, we go back and build the libraries from
# source using the compiler we just built.  We also build profiling
# versions of the libraries at this point.

REAL_LIBS_COOKIE = ${WRKDIR}/.real_libs_done

${REAL_LIBS_COOKIE}:
	@echo "GhcWithHscBuiltViaC=NO" >>${WRKSRC}/mk/build.mk
	@echo "GhcLibWays=p" >>${WRKSRC}/mk/build.mk
	@(cd ${WRKSRC}/ghc/rts; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} clean boot all)
	@(cd ${WRKSRC}/ghc/lib; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} clean boot all)
	@(cd ${WRKSRC}/hslibs; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} clean boot all)
	@${TOUCH} ${TOUCH_FLAGS} ${REAL_LIBS_COOKIE}

post-build: ${REAL_LIBS_COOKIE}

.include <bsd.port.mk>
