# New ports collection makefile for:	Java Foundation Classes with Swing
# Date created:		17 May 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jfc
PORTVERSION=	1.1.1
CATEGORIES=	java
MASTER_SITES=	http://java.sun.com/products/jfc/
DISTNAME=	swing1_1_1
EXTRACT_SUFX=	.zip

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Java Foundation Classes (JFC)/Swing

RUN_DEPENDS=	${PREFIX}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk11

USE_ZIP=	YES
RESTRICTED=	"Can only be distributed with value added application"
WRKSRC=		${WRKDIR}/swing-1.1.1fcs
NO_BUILD=	YES
PLIST_SUB=	JFCSUBDIR=${PKGNAME}
ONLY_FOR_ARCHS=	i386

JDK_VERSION=	1.1.8

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE='You must manually fetch the standard zip format distribution from http://www.javasoft.com/products/jfc/download.html and place it in ${DISTDIR} then run make again.'
.endif

do-install:
	@${MKDIR} ${PREFIX}/share/java/classes/${PKGNAME}/
	@${CP} ${WRKSRC}/*.jar ${PREFIX}/share/java/classes/${PKGNAME}/
	@${MKDIR} ${PREFIX}/share/java/${PKGNAME}/
	@${CP} ${WRKSRC}/CHANGES.txt ${PREFIX}/share/java/${PKGNAME}/
	@${CP} ${WRKSRC}/LICENSE.txt ${PREFIX}/share/java/${PKGNAME}/
	@${CP} ${WRKSRC}/README.html ${PREFIX}/share/java/${PKGNAME}/
	@${CP} ${WRKSRC}/README.txt  ${PREFIX}/share/java/${PKGNAME}/
	@${CP} -R ${WRKSRC}/doc      ${PREFIX}/share/java/${PKGNAME}/
	@${CP} -R ${WRKSRC}/examples ${PREFIX}/share/java/${PKGNAME}/

.include <bsd.port.post.mk>
