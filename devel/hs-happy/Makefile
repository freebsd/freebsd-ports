# New ports collection makefile for:	happy
# Date created:				22 December 2000
# Whom:					Simon Marlow <simonmar@microsoft.com>
#
# $FreeBSD$

PORTNAME=	happy
PORTVERSION=	1.13
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.haskell.org/happy/dist/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
PKGNAMEPREFIX=	hs-

MAINTAINER=	simonmar@microsoft.com
COMMENT=	An LALR(1) parser generator for the functional language Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/dsssl/modular:${PORTSDIR}/textproc/dsssl-docbook-modular \
		${LOCALBASE}/share/sgml/docbook/catalog:${PORTSDIR}/textproc/docbook \
		${LOCALBASE}/share/sgml/iso8879:${PORTSDIR}/textproc/iso8879 \
		${LOCALBASE}/share/sgml/docbook/3.1:${PORTSDIR}/textproc/docbook-310 \
		jade:${PORTSDIR}/textproc/jade
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//g}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_SUB=	HAPPY_VERSION=${PORTVERSION}

BOOT_COOKIE = ${WRKDIR}/.boot_done

${BOOT_COOKIE}:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} boot)

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
