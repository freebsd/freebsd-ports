# New ports collection makefile for:	barbecue
# Date created:		21 May 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	barbecue
PORTVERSION=	1.0.6d
CATEGORIES=	graphics print java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A Java barcode generator

RUN_DEPENDS=	${JAVALIBDIR}/jdom.jar:${PORTSDIR}/java/jdom

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes

JARFILES=	${PORTNAME}-${PORTVERSION}.jar
PLIST_FILES+=	%%JAVAJARDIR%%/${JARFILES:S|-${PORTVERSION}||}	\
		%%JAVAJARDIR%%/LICENSE.barbecue.txt

.if defined(WITH_TOMCAT41)
RUN_DEPENDS+=	${LOCALBASE}/bin/tomcat41ctl:${PORTSDIR}/www/jakarta-tomcat41
JAKARTA_HOME=	${LOCALBASE}/jakarta-tomcat4.1
PLIST_FILES+=	${JAKARTA_HOME:S|^${LOCALBASE}/||}/webapps/${PORTNAME}.war
.endif

PORTDOCS=	*

pre-everything::
.if !defined(WITH_TOMCAT41)
	@${ECHO_MSG} '*********************************************************'
	@${ECHO_MSG} '* To use Barbecue as a servlet, define WITH_TOMCAT41.   *'
	@${ECHO_MSG} '*********************************************************'
.endif

post-extract:
	${MV} ${WRKSRC}/${JARFILES} ${WRKSRC}/${JARFILES:S|-${PORTVERSION}||}

do-install:
	${INSTALL_DATA} ${JARFILES:S|-${PORTVERSION}||:S|^|${WRKSRC}/|} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${JAVAJARDIR}/LICENSE.barbecue.txt
.if defined(WITH_TOMCAT41)
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.war ${JAKARTA_HOME}/webapps
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
	@${CP} -R ${WRKSRC}/docs/* ${DOCSDIR}
	@${CP} -R ${WRKSRC}/examples ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
