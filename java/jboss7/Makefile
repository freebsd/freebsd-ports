# Created by: Alexander Yerenkow <yerenkow@gmail.com>
# $FreeBSD$

PORTNAME=	jboss
PORTVERSION=	${JBOSS_BRANCH}.1
CATEGORIES=	java www
MASTER_SITES=	http://download.jboss.org/jbossas/${JBOSS_BRANCH}/${DISTNAME}/
PKGNAMESUFFIX=	-as
DISTNAME=	jboss-as-${PORTVERSION}.Final
DIST_SUBDIR=	${DISTNAME}

MAINTAINER=	yerenkow@gmail.com
COMMENT=	JBoss AS 7.1.1.Final Brontes

LICENSE=	LGPL21

DEPRECATED=	Unsupported, replaced by wildfly
EXPIRATION_DATE=2017-02-07

JBOSS_MAJOR=	7
JBOSS_BRANCH=	${JBOSS_MAJOR}.1

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USER=		www
GROUP=		www
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${DISTNAME} && cd ${WRKSRC} && ${FIND} . |\
		${CPIO} -pdmu -R ${USER}:${GROUP} ${STAGEDIR}${PREFIX}/${DISTNAME}

.include <bsd.port.mk>
