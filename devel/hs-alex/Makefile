# New ports collection makefile for:	alex
# Date created:				29 January 2003
# Whom:					Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$

PORTNAME=	alex
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.haskell.org/alex/dist/
PKGNAMEPREFIX=	hs-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	stolz@i2.informatik.rwth-aachen.de
COMMENT=	Alex is a tool for generating lexical analysers in Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	jade:${PORTSDIR}/textproc/jade
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_SUB=	"PORTVERSION=${PORTVERSION}"

.if !defined(NOPORTDOCS)
post-build:
	${GMAKE} -C ${WRKSRC}/alex/doc ps
.endif

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${FIND} ${WRKSRC}/alex/examples -type f -exec ${INSTALL_DATA} \{\} ${EXAMPLESDIR} \;
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/alex/doc/alex.ps ${DOCSDIR}
.endif

.include <bsd.port.mk>
