# New ports collection makefile for:	happy
# Date created:				22 December 2000
# Whom:					Simon Marlow <simonmar@microsoft.com>
#
# $FreeBSD$

PORTNAME=	happy
PORTVERSION=	1.18.4
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	An LALR(1) parser generator for the functional language Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4
.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/html:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt
PLIST_SUB+=	RMLIC="@comment "
.else
PLIST_SUB+=	RMLIC=""
.endif

PLIST_SUB+=	SUBDIR=share/${PORTNAME}-${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	LICENSE html
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}-${PORTVERSION}
PORTEXAMPLES=	*

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262:env
CONFIGURE_ARGS=	--ghc --prefix=${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+' ${WRKSRC}/doc/configure.ac

do-configure:
	cd ${WRKSRC} && runhaskell Setup.lhs configure ${CONFIGURE_ARGS}
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
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/doc && ${CP} -R happy/ ${DOCSDIR}/html)
.endif

.include <bsd.port.mk>
