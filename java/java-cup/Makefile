# New ports collection makefile for:	cup
# Date created:		10 May 1998
# Whom:			nordwick@xcf.berkeley.edu
#
# $FreeBSD$
#

PORTNAME=	cup
PORTVERSION=	11.a
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	http://www2.cs.tum.edu/projects/cup/ \
		http://mirrors.mcdermottroe.com/www2.cs.tum.edu/projects/cup/ 
PKGNAMEPREFIX=	java-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-v${PORTVERSION:S|.||}-20050516-sources

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An LALR parser generator in Java

USE_JAVA=	yes
USE_ANT=	yes
WRKSRC=		${WRKDIR}/cup-tum

# Silly hack because the naming in CUP is all over the place
DISTJARNAME=	${PKGNAMEPREFIX}${PORTNAME}-10k-TUM

PLIST_FILES=	%%JAVAJARDIR%%/${DISTJARNAME}.jar \
		%%JAVAJARDIR%%/${DISTJARNAME}-runtime.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/${DISTJARNAME}.jar ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/${DISTJARNAME}-runtime.jar ${JAVAJARDIR}

.include <bsd.port.mk>
