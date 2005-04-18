# New ports collection makefile for:	tclhaskell-ghc
# Date created:				2003-03-05
# Whom:					Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$

PORTNAME=	tclhaskell
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	devel haskell tcl83
MASTER_SITES=	http://www.dcs.gla.ac.uk/~meurig/TclHaskell/
PKGNAMEPREFIX=	hs-
PKGNAMESUFFIX=	-${GHCDEP}
DISTNAME=	TclHaskell1_2

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Tcl/Tk binding for Haskell

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83
BUILD_DEPENDS=	${GHC}:${PORTSDIR}/lang/${GHCDEP}
RUN_DEPENDS=	${GHC}:${PORTSDIR}/lang/${GHCDEP}

.if defined(WITH_GHC5)
GHC=		ghc-5.04.3
GHCDEP=		ghc5
.else
GHC=		ghc-6.4
GHCDEP=		ghc
.endif

SUB_FILES=	pkg-install
SUB_LIST=	GHC_VERSION="${GHC_VERSION}"
WRKSRC=		${WRKDIR}/TclHaskell1.2/src
USE_GMAKE=	YES

GHC_VERSION=	${GHC:S/^ghc-//} # `${LOCALBASE}/bin/${GHC} --numeric-version`
GHC_LIB=	${LOCALBASE}/lib/${GHC}
PLIST_SUB+=	GHC_VERSION="${GHC_VERSION}"
PKGINSTALL=	${WRKDIR}/pkg-install
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}" \
		MKDIR="${MKDIR}" GHC="${GHC}"
MAKE_ARGS+=	CC="${CC}" GHC="${GHC}" CC_OPTS="${CFLAGS}" \
		CC_INC="-I${X11BASE}/include -I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.3 -I${LOCALBASE}/include/tk8.3" \
		CCLIB="-L${X11BASE}/lib/X11 -L${LOCALBASE}/lib" \
		IMPORTS="${GHC_LIB}/imports/tclhaskell" TCLLIBS="-ltk83 -ltcl83" \
		TCL_REQ="-ltk83 -ltcl83" PREFIX="${GHC_LIB}"

pre-everything::
	@${ECHO}
	@${ECHO} "This port prefers lang/ghc6. To build this port with"
	@${ECHO} "the Glasgow Haskell Compiler 5.x, restart this build with"
	@${ECHO} "WITH_GHC5=YES."
	@${ECHO}

post-install:
	@${MKDIR} ${EXAMPLESDIR}/images
.for f in licence.txt demo
	${FIND} ${WRKSRC}/../${f} -maxdepth 1 -type f -exec ${INSTALL_DATA} \{\} ${EXAMPLESDIR}/ \;
.endfor
	${INSTALL_DATA} ${WRKSRC}/../demo/images/* ${EXAMPLESDIR}/images/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../doc/* ${DOCSDIR}/
.endif
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} dummy POST-INSTALL

.include <bsd.port.mk>
