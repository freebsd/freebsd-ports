# New ports collection makefile for:    JDK1.1 Collections package
# Date created:		1999/08/08
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	collections
PORTVERSION=	1.1
CATEGORIES=	java
DISTNAME=	collections1_1
EXTRACT_SUFX=	.zip

MAINTAINER=	noway@nohow.demon.co.uk

RUN_DEPENDS=	${PREFIX}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk

USE_ZIP=	YES

WRKSRC=		${WRKDIR}/1.1collections
JDK_VERSION=	1.1.8
NO_BUILD=	yes
NO_CDROM=	"See the license"

.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	"You must manually fetch the distribution from http://java.sun.com/beans/infobus/index.html and place it in ${DISTDIR} then run make again"
.endif

do-install:
	@${MKDIR} ${PREFIX}/share/java/classes/
	@${CP} ${WRKSRC}/lib/*.jar ${PREFIX}/share/java/classes/
	@${MKDIR} ${PREFIX}/share/java/${PKGNAME}/
	@${CP} -R ${WRKSRC}/doc/* ${PREFIX}/share/java/${PKGNAME}/

.include <bsd.port.post.mk>
