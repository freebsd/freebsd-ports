# New ports collection makefile for:    JavaMail API Implementation Version 1.1.2
# Version required:	1.1.2
# Date created:		1999/08/08
# Whom:			Jose Marques
#
# $FreeBSD$
#

DISTNAME=	javamail1_1_2
PKGNAME=	javamail-1.1.2
CATEGORIES=	java
EXTRACT_SUFX=	.zip

MAINTAINER=	noway@nohow.demon.co.uk

RUN_DEPENDS=	${PREFIX}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk \
		${PREFIX}/share/java/classes/activation.jar:${PORTSDIR}/java/jaf

USE_ZIP=	YES

WRKSRC=		${WRKDIR}/javamail-1.1.2
JDK_VERSION=	1.1.8
NO_BUILD=	yes
NO_CDROM=	"See the license"

.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	"You must manually fetch the distribution from http://www.javasoft.com/products/javamail/index.html and place it in ${DISTDIR} then run make again"
.endif

do-install:
	@cd ${WRKSRC}; \
		${MKDIR} ${PREFIX}/share/java/classes/; \
		${CP} ${WRKSRC}/mail.jar ${PREFIX}/share/java/classes/; \
		${MKDIR} ${PREFIX}/share/java/${PKGNAME}/; \
		${CP} CHANGES.txt LICENSE.txt NOTES.txt README.txt ${PREFIX}/share/java/${PKGNAME}/; \
		${CP} -R demo ${PREFIX}/share/java/${PKGNAME}/; \
		${CP} -R docs ${PREFIX}/share/java/${PKGNAME}/

.include <bsd.port.post.mk>
