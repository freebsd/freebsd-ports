# New ports collection makefile for:	JDK tutorial
# Date created:		Tue Mar 23 10:18:20 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	jdk-tutorial
PORTVERSION=	1.1.8
PORTREVISION=	2
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.javasoft.com/docs/
DISTNAME=	tutorial

MAINTAINER=	martti.kuparinen@iki.fi

NO_WRKSUBDIR=	yes
RESTRICTED=	"This software is under license and export control."
NO_BUILD=	yes
PLIST_SUB+=	VERSION=${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/MESSAGE

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${PREFIX}/jdk${PORTVERSION}/docs/books/tutorial
	(cd ${WRKSRC} && ${TAR} -cf - * ) \
	    | (cd ${PREFIX}/jdk${PORTVERSION}/docs/books/tutorial \
	        && ${TAR} -xf -)
	@${SED} s+!!PREFIX!!+${PREFIX}+g < ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
	@${RM} ${PKGMESSAGE}

.include <bsd.port.post.mk>
