# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	slf4j
PORTVERSION=	1.7.21
CATEGORIES=	devel java
MASTER_SITES=	http://www.slf4j.org/dist/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Simple facade or abstraction for various logging frameworks

LICENSE=	MIT

USE_JAVA=	1.4+
NO_BUILD=	YES

JARFILES=	slf4j-migrator.jar \
		slf4j-simple.jar \
		jcl-over-slf4j.jar \
		log4j-over-slf4j.jar \
		slf4j-ext.jar \
		slf4j-jdk14.jar \
		slf4j-nop.jar \
		jul-to-slf4j.jar \
		slf4j-jcl.jar \
		slf4j-log4j12.jar

PLIST_FILES=	%%JAVAJARDIR%%/slf4j-api.jar \
		${JARFILES:S,^,%%DATADIR%%/,}

do-install:
	${INSTALL_DATA} ${WRKSRC}/slf4j-api-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/slf4j-api.jar
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for jarfile in ${JARFILES}
	${INSTALL_DATA} ${WRKSRC}/${jarfile:S,.jar$,-${PORTVERSION}.jar,} ${STAGEDIR}${DATADIR}/${jarfile}
.endfor

.include <bsd.port.mk>
