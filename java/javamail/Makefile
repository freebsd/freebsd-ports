# New ports collection makefile for:    JavaMail API Implementation
# Date created:		1999/08/08
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	javamail
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	#
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}

MAINTAINER=	java@freebsd.org

RUN_DEPENDS=	${LOCALBASE}/share/java/classes/activation.jar:${PORTSDIR}/java/jaf

USE_ZIP=	YES
USE_JAVA=	1.1+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
NO_CDROM=	"See the license"
TARGET_DIR=	${PREFIX}/share/java/${PKGNAME}
PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}
DOWNLOAD_URL=	"http://java.sun.com/products/javamail/"

.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	"You must manually fetch the distribution from ${DOWNLOAD_URL} and place it in ${DISTDIR} then run make again"
.endif

do-install:
	${MKDIR} ${TARGET_DIR}
	${CP} -R ${WRKSRC}/* ${TARGET_DIR}
	${LN} -sf ${TARGET_DIR}/lib/imap.jar ${PREFIX}/share/java/classes/imap.jar
	${LN} -sf ${TARGET_DIR}/mail.jar ${PREFIX}/share/java/classes/mail.jar
	${LN} -sf ${TARGET_DIR}/lib/mailapi.jar ${PREFIX}/share/java/classes/mailapi.jar
	${LN} -sf ${TARGET_DIR}/lib/pop3.jar ${PREFIX}/share/java/classes/pop3.jar
	${LN} -sf ${TARGET_DIR}/lib/smtp.jar ${PREFIX}/share/java/classes/smtp.jar

.include <bsd.port.post.mk>
