# New ports collection makefile for: hs-haddock-docs
# Date created:        February 22 2008
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	haddock-docs
PORTVERSION=	2.0.0.0
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.haskell.org/haddock/dist/
PKGNAMEPREFIX=	hs-
DISTNAME=	haddock-${PORTVERSION}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Documentation for Haddock

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:261:env

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		haddock:${PORTSDIR}/devel/hs-haddock \
		HsColour:${PORTSDIR}/print/hs-hscolour

BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/dsssl/modular:${PORTSDIR}/textproc/dsssl-docbook-modular \
		docbook<2:${PORTSDIR}/textproc/docbook \
		${LOCALBASE}/share/sgml/iso8879:${PORTSDIR}/textproc/iso8879 \
		${LOCALBASE}/share/sgml/docbook/3.1:${PORTSDIR}/textproc/docbook-310 \
		${LOCALBASE}/share/xsl/docbook/catalog:${PORTSDIR}/textproc/docbook-xsl \
		jade:${PORTSDIR}/textproc/jade \
		xsltproc:${PORTSDIR}/textproc/libxslt

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//g}
CONFIGURE_ARGS=	--prefix=${PREFIX}

HSCOLOUR_VERSION=	1.9
HSCOLOUR_DATADIR=	${PREFIX}/share/hscolour-${HSCOLOUR_VERSION}

CABAL_CMD=	runghc Setup.lhs

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
PLIST_SUB=	DOCSDIR_REL=${DOCSDIR_REL}

.SILENT:

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/share/sgml/catalog||' ${WRKSRC}/doc/configure.ac

do-configure:
	cd ${WRKSRC} && ${CABAL_CMD} configure --ghc ${CONFIGURE_ARGS}
	cd ${WRKSRC}/doc && ${AUTOCONF} && ./configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${CABAL_CMD} build && \
		${CABAL_CMD} haddock --executables --hyperlink-source --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
	cd ${WRKSRC}/doc && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} html

do-install:
	${MKDIR} ${DOCSDIR}/html && \
		cd ${WRKSRC}/dist/doc/html/haddock && ${CP} -R * ${DOCSDIR}/html
	${MKDIR} ${DOCSDIR}/users_guide && \
		cd ${WRKSRC}/doc/haddock && ${CP} -R * ${DOCSDIR}/users_guide

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
