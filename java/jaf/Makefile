# New ports collection makefile for:    JavaBeans Activation Framework (JAF)
# Date created:		1999/08/08
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	jaf
PORTVERSION=	1.0.1
CATEGORIES=	java
DISTNAME=	jaf1_0_1
EXTRACT_SUFX=	.zip

MAINTAINER=	noway@nohow.demon.co.uk

RUN_DEPENDS=	${PREFIX}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk

USE_ZIP=	YES

WRKSRC=		${WRKDIR}/jaf-1.0.1
JDK_VERSION=	1.1.8
NO_BUILD=	yes
NO_CDROM=	"See the license"

.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	"You must manually fetch the distribution from http://java.sun.com/beans/glasgow/jaf.html and place it in ${DISTDIR} then run make again"
.endif

do-install:
	@cd ${WRKSRC}; \
		${MKDIR} ${PREFIX}/share/java/classes/; \
		${CP} ${WRKSRC}/activation.jar ${PREFIX}/share/java/classes/; \
		${MKDIR} ${PREFIX}/share/java/${PKGNAME}/; \
		${CP} LICENSE.txt README.txt RELNOTES.txt ${PREFIX}/share/java/${PKGNAME}/; \
		${CP} -R demo ${PREFIX}/share/java/${PKGNAME}/; \
		${CP} -R docs ${PREFIX}/share/java/${PKGNAME}/

.include <bsd.port.post.mk>
