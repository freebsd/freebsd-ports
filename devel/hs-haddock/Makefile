# New ports collection makefile for:	haddock
# Date created:				09 May 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	haddock
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.haskell.org/haddock/
PKGNAMEPREFIX=	hs-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	A documentation tool for Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/dsssl/modular:${PORTSDIR}/textproc/dsssl-docbook-modular \
		${LOCALBASE}/share/sgml/docbook/catalog:${PORTSDIR}/textproc/docbook \
		${LOCALBASE}/share/sgml/iso8879:${PORTSDIR}/textproc/iso8879 \
		${LOCALBASE}/share/sgml/docbook/3.1:${PORTSDIR}/textproc/docbook-310 \
		jade:${PORTSDIR}/textproc/jade
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//g}
USE_SIZE=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
PLIST_SUB+=	HADDOCK_VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/share/sgml/catalog||' ${WRKSRC}/configure

post-build:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/haddock/doc && \
	 ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} html)
.endif

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/haddock/doc && ${CP} -R haddock ${PREFIX}/share/doc)
.endif

.include <bsd.port.mk>
