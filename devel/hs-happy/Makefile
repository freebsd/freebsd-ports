# New ports collection makefile for:	happy
# Date created:				22 December 2000
# Whom:					Simon Marlow <simonmar@microsoft.com>
#
# $FreeBSD$

PORTNAME=	happy
PORTVERSION=	1.15
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.haskell.org/happy/dist/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	simonmar@microsoft.com
COMMENT=	An LALR(1) parser generator for the functional language Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/html:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//g}
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_SUB=	HAPPY_VERSION=${PORTVERSION}
PORTDOCS=	*

BOOT_COOKIE = ${WRKDIR}/.boot_done

${BOOT_COOKIE}:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} boot)

post-patch:
	@${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+' ${WRKSRC}/configure

pre-build: ${BOOT_COOKIE}

post-build:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/happy/doc && \
	 ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} html)
.endif

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/happy/doc && ${CP} -R happy ${PREFIX}/share/doc)
.endif

.include <bsd.port.mk>
