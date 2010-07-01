# Ports collection Makefile for:    Castor
# Date created:         2005/05/12
# Whom:                 Adam VanderHook <acidos@bandwidth-junkies.net>
#
# $FreeBSD$
#

PORTNAME=	castor
PORTVERSION=	1.3.1
CATEGORIES=	java devel
MASTER_SITES=	http://dist.codehaus.org/castor/${PORTVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	utisoft@gmail.com
COMMENT=	Data binding for XML (JAXB) and SQL database (JDO)
LICENSE=	ASL

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

JARSUFXS=	-anttasks.jar \
			-codegen.jar \
			-core.jar \
			-ddlgen.jar \
			-jdo.jar \
			-xml-schema.jar \
			-xml.jar \
			.jar

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}-anttasks.jar \
				%%JAVAJARDIR%%/${PORTNAME}-codegen.jar \
				%%JAVAJARDIR%%/${PORTNAME}-core.jar \
				%%JAVAJARDIR%%/${PORTNAME}-ddlgen.jar \
				%%JAVAJARDIR%%/${PORTNAME}-jdo.jar \
				%%JAVAJARDIR%%/${PORTNAME}-xml-schema.jar \
				%%JAVAJARDIR%%/${PORTNAME}-xml.jar \
				%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
.for f in ${JARSUFXS}
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}${f}..."
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}${f} \
		${JAVAJARDIR}/${PORTNAME}${f}
	@${ECHO_MSG} " [ DONE ]"
.endfor

.include <bsd.port.mk>
