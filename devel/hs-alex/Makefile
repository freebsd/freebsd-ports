# New ports collection makefile for:	alex
# Date created:				29 January 2003
# Whom:					Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$

PORTNAME=	alex
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.haskell.org/alex/dist/
PKGNAMEPREFIX=	hs-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Alex is a tool for generating lexical analysers in Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	jade:${PORTSDIR}/textproc/jade \
		jadetex:${PORTSDIR}/print/jadetex \
		${LOCALBASE}/share/sgml/docbook/3.1/docbook.dtd:${PORTSDIR}/textproc/docbook-310 \
		${LOCALBASE}/share/sgml/docbook/dsssl:${PORTSDIR}/textproc/dsssl-docbook-modular
.endif

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

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
