# New ports collection makefile for:	JDK tutorial
# Version required:	1.1.8
# Date created:		Tue Mar 23 10:18:20 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

DISTNAME=	tutorial
PKGNAME=	jdk-tutorial-1.1.8
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.javasoft.com/docs/

MAINTAINER=	martti.kuparinen@ericsson.com

VERSION=	1.1.8
WRKSRC=		${WRKDIR}
RESTRICTED=	"This software is under license and export control."
NO_BUILD=	yes
PLIST_SUB+=	VERSION=${VERSION}
PKGMESSAGE= ${WRKDIR}/MESSAGE

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${PREFIX}/jdk${VERSION}/docs/books/tutorial
	(cd ${WRKSRC} && ${TAR} -cf - * ) \
	    | (cd ${PREFIX}/jdk${VERSION}/docs/books/tutorial && ${TAR} -xf -)
	@${SED} s+!!PREFIX!!+${PREFIX}+g < ${PKGDIR}/MESSAGE > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
	@${RM} ${PKGMESSAGE}

.include <bsd.port.post.mk>
