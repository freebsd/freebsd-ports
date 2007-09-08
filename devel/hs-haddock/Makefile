# New ports collection makefile for:	haddock
# Date created:				09 May 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	haddock
PORTVERSION=	0.8
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
		docbook<2:${PORTSDIR}/textproc/docbook \
		${LOCALBASE}/share/sgml/iso8879:${PORTSDIR}/textproc/iso8879 \
		${LOCALBASE}/share/sgml/docbook/3.1:${PORTSDIR}/textproc/docbook-310 \
		${LOCALBASE}/share/xsl/docbook/catalog:${PORTSDIR}/textproc/docbook-xsl \
		jade:${PORTSDIR}/textproc/jade \
		xsltproc:${PORTSDIR}/textproc/libxslt
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//g}
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:259:env

PLIST_SUB+=	HADDOCK_VERSION=${PORTVERSION}
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/share/sgml/catalog||' ${WRKSRC}/doc/configure.ac

do-configure:
	cd ${WRKSRC} && runhaskell Setup.lhs configure --ghc ${CONFIGURE_ARGS}
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc && ${AUTOCONF} && ./configure ${CONFIGURE_ARGS}
.endif

do-build:
	cd ${WRKSRC} && runhaskell Setup.lhs build

post-build:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/doc && \
	 ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} html)
.endif

do-install:
	cd ${WRKSRC} && runhaskell Setup.lhs install

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/haddock
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/doc && ${CP} -R haddock ${PREFIX}/share/doc)
.endif

.include <bsd.port.mk>
