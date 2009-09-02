# New ports collection makefile for:   c2hs
# Date created:        23 August 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	c2hs
PORTVERSION=	0.16.0
PORTREVISION=	2
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	C->Haskell, an Interface Generator for Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-language-c-ghc>=0.3.1.1:${PORTSDIR}/devel/hs-language-c-ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

GHC_VERSION=	6.10.4
C2HS_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DATADIR=	${PREFIX}/share/${DISTNAME}
DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
C2HS_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		C2HS_VERSION=${C2HS_VERSION} \
		C2HS_LIBDIR_REL=${C2HS_LIBDIR_REL}

MAN1=		c2hs.1

.if defined(NOPORTDOCS)
PLIST_SUB+=		NOPORTDOCS=""
.else
PLIST_SUB+=		NOPORTDOCS="@comment "
.endif

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/html:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt
USE_GMAKE=	yes
PORTDOCS=	COPYING users_guide
.endif

.SILENT:

do-configure:
	cd ${WRKSRC} && ${GHC_CMD} --make Setup.hs -o setup -package Cabal \
		     && ${SETUP_CMD} configure --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build

.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} html)
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install \
		     && ${INSTALL_MAN} ${WRKSRC}/doc/man1/c2hs.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/doc && ${CP} -R users_guide ${DOCSDIR})
.endif

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
