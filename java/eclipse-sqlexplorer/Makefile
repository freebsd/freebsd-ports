# New ports collection makefile for:	eclipse-sqlexplorer
# Date created:				August 14, 2004
# Whom:					sugimura@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	sqlexplorer
PORTVERSION=	2.2.2
PORTREVISION=	2
CATEGORIES=	java
MASTER_SITES=	#
PKGNAMEPREFIX=	eclipse-
DISTNAME=	net.java.${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	eclipse

MAINTAINER=	sugimura@jp.FreeBSD.ORG
COMMENT=	A visual database query tool for Eclipse

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
DOWNLOAD_URL=	https://sqlexplorer.dev.java.net/servlets/ProjectDocumentList

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/features ${PREFIX}/eclipse

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=	${PRINTF}
IGNORE=	:\n\
Because of a specific structure of dev.java.net, you must fetch the\n\
distribution manually. Please acccess\n\
\n\
  ${DOWNLOAD_URL}\n\
\n\
with a web browser and click its filename.\n\
Please place the downloaded ${DISTNAME}${EXTRACT_SUFX} in ${DISTDIR}/${DIST_SUBDIR}.\n
.endif

.include <bsd.port.post.mk>
