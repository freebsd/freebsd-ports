# New ports collection makefile for: hs-haddock-docs
# Date created:        February 22 2008
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	haddock
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.haskell.org/haddock/dist/ \
		http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
PKGNAMESUFFIX=	-doc

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Documentation for Haddock

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262:env

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		HsColour:${PORTSDIR}/print/hs-hscolour \
		hs-ghc-paths>=0.1.0.5:${PORTSDIR}/devel/hs-ghc-paths

PORT_HADDOCK!=	(cd  ${.CURDIR}/../../lang/ghc && ${MAKE} -V PORT_HADDOCK)
.if ${PORT_HADDOCK} == 11
ECHO_MSG=	${PRINTF} "%b"
IGNORE+=	\n\t The ${LOCALBASE}/bin/haddock executable was already installed\n
IGNORE+=	\t by the lang/ghc port, setting the option WITH_HADDOCK.\n
IGNORE+=	\t You have to reinstall this last one with the right option\n
IGNORE+=	\t WITHOUT_HADDOCK.\n\c
.else
BUILD_DEPENDS+=	hs-haddock=${PKGVERSION}:${PORTSDIR}/devel/hs-haddock
RUN_DEPENDS=	hs-haddock=${PKGVERSION}:${PORTSDIR}/devel/hs-haddock
.endif

BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/html:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//g}
CONFIGURE_ARGS=	--prefix=${PREFIX}

HSCOLOUR_VERSION=	1.15
HSCOLOUR_DATADIR=	${PREFIX}/share/hscolour-${HSCOLOUR_VERSION}

CABAL_CMD=	runghc Setup.lhs

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}

.SILENT:

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/share/sgml/catalog|| ; \
		s|/usr/local/share/xsl/docbook|${LOCALBASE}/share/xsl/docbook|' \
		${WRKSRC}/doc/configure.ac

do-configure:
	cd ${WRKSRC} && ${CABAL_CMD} configure --ghc --haddock-options=-w ${CONFIGURE_ARGS}
	cd ${WRKSRC}/doc && ${AUTOCONF} && ./configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${CABAL_CMD} haddock --executables --hyperlink-source --executables \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
	cd ${WRKSRC}/doc && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} html

do-install:
	${MKDIR} ${DOCSDIR}/html && \
		cd ${WRKSRC}/dist/doc/html/haddock && ${COPYTREE_SHARE} \*  ${DOCSDIR}/html
	${MKDIR} ${DOCSDIR}/users_guide && \
		cd ${WRKSRC}/doc/haddock && ${COPYTREE_SHARE} \* ${DOCSDIR}/users_guide

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
