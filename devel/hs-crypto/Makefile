# New ports collection makefile for:   crypto
# Date created:        23 June 2003
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	crypto
PORTVERSION=	0.2.0
CATEGORIES=	devel haskell
MASTER_SITES=	http://haskell.cs.yale.edu/packages/downloads/
PKGNAMEPREFIX=	hs-
EXTRACT_SUFX=	.tar

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	A Haskell Cryptographic Library

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

.if !defined(NOPORTDOCS)
BUILD_DEPENDS=	haddock:${PORTSDIR}/devel/hs-haddock
.endif

WRKSRC=		${WRKDIR}
USE_REINPLACE=	yes
USE_GMAKE=	yes
ALL_TARGET=	# empty

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/Makefile ${WRKSRC}/package.conf
	@${REINPLACE_CMD} -e 's|PKCS#5|PKCS 5|' \
		${WRKSRC}/Codec/Encryption/Padding.hs

do-configure:
	@(cd ${WRKSRC} && ${GMAKE} depend)

.if !defined(NOPORTDOCS)
post-build:
	@(cd ${WRKSRC} && ${GMAKE} doc)
post-install:
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} && \
		${INSTALL_DATA} *.html ReadMe.* haddock.css haskell_icon.gif ${DOCSDIR})
.endif

.include <bsd.port.mk>
