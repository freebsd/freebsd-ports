# New ports collection makefile for:	Java module for SQL Relay
# Date created:		2 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	${SQLRELAY_PORTNAME}
PORTVERSION=	${SQLRELAY_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	databases java
MASTER_SITES=	# none
PKGNAMEPREFIX=	java-
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java classes to access to SQL Relay

EXTRACT_DEPENDS=	${NONEXISTENT}:${SQLRELAY_PORTDIR}:patch
BUILD_DEPENDS=	${LOCALBASE}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk11
LIB_DEPENDS=	sqlrclient.0:${SQLRELAY_PORTDIR}
RUN_DEPENDS=	${LOCALBASE}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk11

JDK_VERSION?=		1.1.8

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/src/api/java
INSTALL_WRKSRC=	${BUILD_WRKSRC}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${SQLRELAY_CONFIGURE_ARGS} \
		--with-java-prefix="${LOCALBASE}/jdk${JDK_VERSION}"

.include "${.CURDIR}/../sqlrelay/Makefile.common"

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -fs `${SQLRELAY_WRKSRC_CMD}` ${WRKSRC}
	${RM} -f ${WRKSRC}/config.cache

.include <bsd.port.mk>
