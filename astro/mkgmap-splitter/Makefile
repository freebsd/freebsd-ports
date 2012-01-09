# New ports collection makefile for:	mkgmap-splitter
# Date created:		03 May 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	splitter
PORTVERSION=	r198
CATEGORIES=	astro converters java
MASTER_SITES=	http://www.mkgmap.org.uk/splitter/ \
		http://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	mkgmap-

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tile splitter for mkgmap

NO_BUILD=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.6+

SUB_FILES=	${PORTNAME}.sh

PORTDOCS=	*

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}

do-install:
	${MKDIR} ${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${DATADIR}/lib/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PKGNAMEPREFIX}${PORTNAME}
.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/intro.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
