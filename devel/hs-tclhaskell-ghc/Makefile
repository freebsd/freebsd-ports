# New ports collection makefile for:	tclhaskell-ghc
# Date created:				2003-03-05
# Whom:					Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$

PORTNAME=	tclhaskell-ghc
PORTVERSION=	1.2
CATEGORIES=	devel haskell tcl83
MASTER_SITES=	http://www.dcs.gla.ac.uk/~meurig/TclHaskell/
PKGNAMEPREFIX=	hs-
DISTNAME=	TclHaskell1_2

MAINTAINER=	stolz@i2.informatik.rwth-aachen.de
COMMENT=	Tcl/Tk binding for Haskell

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83
BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

WRKSRC=		${WRKDIR}/TclHaskell1.2/src
USE_GMAKE=	YES
USE_REINPLACE=	YES

GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
GHC_LIB=	${LOCALBASE}/lib/ghc-${GHC_VERSION}
PLIST_SUB+=	GHC_VERSION="${GHC_VERSION}"
PKGINSTALL=	${WRKDIR}/pkg-install
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}" \
		MKDIR="${MKDIR}"

post-patch:
	${REINPLACE_CMD} -e "s,/local.*tclhaskell,${GHC_LIB}," ${WRKSRC}/Makefile

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
	@${SED} -e s,GHC_VERSION,${GHC_VERSION}, <${MASTERDIR}/pkg-install.in >${PKGINSTALL}
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} dummy POST-INSTALL
	@${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
