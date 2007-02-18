# New ports collection makefile for:	alex
# Date created:				29 January 2003
# Whom:					Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$

PORTNAME=	alex
PORTVERSION=	2.1.0
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.haskell.org/alex/dist/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Alex is a tool for generating lexical analysers in Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/html:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt
.endif

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:259:env
CONFIGURE_ARGS=	--ghc --prefix=${PREFIX}

PLIST_SUB=	PORTVERSION="${PORTVERSION}"
PORTDOCS=	*

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
	@${STRIP_CMD} ${PREFIX}/bin/alex
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${FIND} ${WRKSRC}/examples -type f -exec ${INSTALL_DATA} \{\} ${EXAMPLESDIR} \;
	@(cd ${WRKSRC}/doc && ${CP} -R alex ${PREFIX}/share/doc)
.endif

.include <bsd.port.mk>
