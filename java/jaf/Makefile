# New ports collection makefile for:    JavaBeans Activation Framework (JAF)
# Date created:		1999/08/08
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	jaf
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	#
DISTNAME=	${PORTNAME}1_0_1

MAINTAINER=	noway@nohow.demon.co.uk

USE_ZIP=	YES
USE_JAVA=	1.1+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
NO_CDROM=	"See the license"
TARGET_DIR=	${PREFIX}/share/java/${PKGNAME}
PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}
DOWNLOAD_URL=	"http://java.sun.com/cgi-bin/download3.cgi?config-file=jaf1_0_1.config&platform=zip&button=continue"

.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	"You must manually fetch the distribution from ${DOWNLOAD_URL} and place it in ${DISTDIR} then run make again"
.endif

do-install:
	${MKDIR} ${PREFIX}/share/java/classes
	${MKDIR} ${TARGET_DIR}
	${CP} -R ${WRKSRC}/* ${TARGET_DIR}
	${LN} -sf ${TARGET_DIR}/activation.jar ${PREFIX}/share/java/classes/activation.jar

.include <bsd.port.post.mk>
