# New ports collection makefile for:	haddock
# Date created:				09 May 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	haddock
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.haskell.org/haddock/
PKGNAMEPREFIX=	hs-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A documentation tool for Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/dsssl/modular:${PORTSDIR}/textproc/dsssl-docbook-modular \
		${LOCALBASE}/share/sgml/docbook/catalog:${PORTSDIR}/textproc/docbook \
		${LOCALBASE}/share/sgml/iso8879:${PORTSDIR}/textproc/iso8879 \
		${LOCALBASE}/share/sgml/docbook/3.1:${PORTSDIR}/textproc/docbook-310 \
		${LOCALBASE}/share/xsl/docbook/catalog:${PORTSDIR}/textproc/docbook-xsl \
		jade:${PORTSDIR}/textproc/jade \
		xsltproc:${PORTSDIR}/textproc/libxslt
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//g}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
PLIST_SUB+=	HADDOCK_VERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Needs perl >= 5.6
.endif

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

.include <bsd.port.post.mk>
