# New ports collection makefile for:	alex
# Date created:				29 January 2003
# Whom:					Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$

PORTNAME=	alex
PORTVERSION=	2.3.1
PORTREVISION=	2
CATEGORIES=	devel haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/alex/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Alex is a tool for generating lexical analysers in Haskell

BUILD_DEPENDS=	ghc>=6.8:${PORTSDIR}/lang/ghc
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/html:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt

PLIST_SUB+=	RMLIC="@comment "
.else
PLIST_SUB+=	RMLIC=""
.endif

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262:env
CONFIGURE_ARGS=	--ghc --prefix=${PREFIX}

PLIST_SUB+=	SUBDIR=share/${PORTNAME}-${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	LICENSE html
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}-${PORTVERSION}
PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/share/xsl/docbook|${LOCALBASE}/share/xsl/docbook|' \
		${WRKSRC}/doc/configure.ac

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
	@${STRIP_CMD} ${PREFIX}/bin/alex
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/doc && ${CP} -R alex/ ${DOCSDIR}/html)
.endif

.include <bsd.port.mk>
