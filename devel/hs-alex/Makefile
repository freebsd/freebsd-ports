# New ports collection makefile for:	alex
# Date created:				29 January 2003
# Whom:					Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$

PORTNAME=	alex
PORTVERSION=	2.0.1
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.haskell.org/alex/dist/ \
		http://www.haskell.org/alex/doc/:doc
PKGNAMEPREFIX=	hs-
DISTFILES=	${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFX} \
		alex.ps:doc
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFX}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Alex is a tool for generating lexical analysers in Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EXAMPLESDIR}
	${FIND} ${WRKSRC}/alex/examples -type f -exec ${INSTALL_DATA} \{\} ${EXAMPLESDIR} \;
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/alex.ps ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
