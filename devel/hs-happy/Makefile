# New ports collection makefile for:	happy
# Date created:				22 December 2000
# Whom:					Simon Marlow <simonmar@microsoft.com>
#
# $FreeBSD$

PORTNAME=	happy
PORTVERSION=	1.11
CATEGORIES=	devel
MASTER_SITES=	http://www.haskell.org/happy/dist/1.11/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	simonmar@microsoft.com

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/dsssl/modular:${PORTSDIR}/textproc/dsssl-docbook-modular \
		${LOCALBASE}/share/sgml/docbook/catalog:${PORTSDIR}/textproc/docbook \
		${LOCALBASE}/share/sgml/iso8879:${PORTSDIR}/textproc/iso8879 \
		jade:${PORTSDIR}/textproc/jade
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//g}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

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
