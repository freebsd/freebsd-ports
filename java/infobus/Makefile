# New ports collection makefile for:    Infobus 1.2
# Date created:		1999/08/08
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	infobus
PORTVERSION=	1.2
CATEGORIES=	java
DISTNAME=	ib12
EXTRACT_SUFX=	.zip

MAINTAINER=	java@freebsd.org
COMMENT=	Enables dynamic exchange of data between JavaBeans(TM)

RUN_DEPENDS=	${PREFIX}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk11 \
		${PREFIX}/share/java/classes/collections.jar:${PORTSDIR}/java/collections

USE_ZIP=	YES

NO_WRKSUBDIR=	yes
JDK_VERSION=	1.1.8
NO_BUILD=	yes
NO_CDROM=	"See the license"

.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	"You must manually fetch the distribution from http://java.sun.com/beans/infobus/index.html and place it in ${DISTDIR} then run make again"
.endif

do-install:
	@cd ${WRKSRC}; \
		${MKDIR} ${PREFIX}/share/java/classes/; \
		${CP} ${WRKSRC}/infobus.jar ${PREFIX}/share/java/classes/; \
		${MKDIR} ${PREFIX}/share/java/${PKGNAME}/; \
		${CP} LICENSE.HTML *.java *.html coffee6.gif examples.mak makefile moneyman.mf ${PREFIX}/share/java/${PKGNAME}/; \
		${CP} -R doc ${PREFIX}/share/java/${PKGNAME}/

.include <bsd.port.post.mk>
