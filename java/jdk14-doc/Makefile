# New ports collection makefile for:	JDK documentation
# Date created:		Mon Mar  8 10:10:42 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	jdk-doc
PORTVERSION=	1.1.8
CATEGORIES=	java
MASTER_SITES=	#
DISTNAME=	jdk-1_1_8_003-doc

MAINTAINER=	ernst@jollem.com

NO_CDROM=	"License does not allow distribution with fee."
RESTRICTED=	"This software is under license and export control."

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE=	"You cannot legally distribute packages"
.endif

PLIST_SUB+=	JDK_HOME=${JDK_HOME:S/^${PREFIX}\///}
JDK_HOME?=	${PREFIX}/jdk${PORTVERSION}

WRKSRC=		${WRKDIR}/jdk${PORTVERSION}

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=You must manually fetch ${DISTNAME}${EXTRACT_SUFX} from http://java.sun.com/jdk/1.1/docs.html, place it in ${DISTDIR} and then run make again
.endif

do-install:
	${MKDIR} ${PREFIX}/jdk${PORTVERSION}
	${CP} -R ${WRKSRC}/docs ${PREFIX}/jdk${PORTVERSION}/
	@${SED} "/%%JDK_HOME%%/s//${JDK_HOME:S/\//\\\//g}/" < ${PKGMESSAGE}

.include <bsd.port.post.mk>
