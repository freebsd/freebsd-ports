# New ports collection makefile for:	generic-haskell
# Date created:				05 July 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	generic-haskell
PORTVERSION=	1.42
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.cs.uu.nl/research/projects/generic-haskell/compiler/coral/
DISTNAME=	gh-${PORTVERSION}-source

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	The Generic Haskell compiler

BROKEN=		"Not compatible with latest GHC yet"
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		bash:${PORTSDIR}/shells/bash

.if !defined(WITHOUT_HUGS)	# otherwise the gh-hugs-wrapper won't work
BUILD_DEPENDS+=	hugs:${PORTSDIR}/lang/hugs
PLIST_SUB+=	HUGS=""
.else
PLIST_SUB+=	HUGS="@comment "
.endif

RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/DrIFT)
BROKEN=		"Does not build with devel/hs-drift installed"
.endif

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS=	--without-upx
USE_GMAKE=	yes
ALL_TARGET=
INSTALL_TARGET=	install

GHC_VERSION=    `${LOCALBASE}/bin/ghc --numeric-version`
PLIST_SUB+=     GHC_VERSION="${GHC_VERSION}"

PATCH_WRKSRC=	${WRKDIR}/${DISTNAME:S/-source//}
WRKSRC=		${WRKDIR}/${DISTNAME:S/-source//}/build
GHLIBDIR=	${PREFIX}/${DISTNAME:S/-source//}
PLIST_SUB+=	GH=${DISTNAME:S/-source//}

post-install:
.if defined(WITHOUT_HUGS)
	@${RM} ${PREFIX}/bin/gh-hugs
.endif
	@${SH} ${PKGINSTALL} generic-haskell POST-INSTALL
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKDIR}/${DISTNAME:S/-source//}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
