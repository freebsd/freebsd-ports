# New ports collection makefile for:	happy
# Date created:				22 December 2000
# Whom:					Simon Marlow <simonmar@microsoft.com>
#
# $FreeBSD$

PORTNAME=	happy
PORTVERSION=	1.17
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.haskell.org/happy/dist/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	An LALR(1) parser generator for the functional language Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/html:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//g}

PLIST_SUB=	HAPPY_VERSION=${PORTVERSION}
PORTDOCS=	*

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:261:env
CONFIGURE_ARGS=	--ghc --prefix=${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+' ${WRKSRC}/doc/configure.ac

do-configure:
	cd ${WRKSRC} && runhaskell Setup.lhs configure
	cd ${WRKSRC}/doc && ${AUTOCONF} && ./configure --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && runhaskell Setup.lhs build
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/doc && \
	 ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} html)
.endif

do-install:
	cd ${WRKSRC} && runhaskell Setup.lhs install

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/happy
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/doc && ${CP} -R happy ${PREFIX}/share/doc)
.endif

.include <bsd.port.mk>
