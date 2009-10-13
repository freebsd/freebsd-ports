# New ports collection makefile for:	slf4j
# Date created:		2009-10-13
# Whom:			Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	slf4j
PORTVERSION=	1.5.8
CATEGORIES=	java devel
MASTER_SITES=	http://www.slf4j.org/dist/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Simple facade or abstraction for various logging frameworks

USE_JAVA=	1.6+
NO_BUILD=	YES

JARFILES=	jcl-over-slf4j.jar \
		jul-to-slf4j.jar \
		log4j-over-slf4j.jar \
		slf4j-api.jar \
		slf4j-ext.jar \
		slf4j-jcl.jar \
		slf4j-jdk14.jar \
		slf4j-log4j12.jar \
		slf4j-migrator.jar \
		slf4j-nop.jar \
		slf4j-simple.jar
PLIST_FILES+=	${JARFILES:S,^,%%JAVAJARDIR%%/,}

do-install:
.for jarfile in ${JARFILES}
	@${INSTALL_DATA} ${WRKSRC}/${jarfile:S,.jar$,-${PORTVERSION}.jar,} ${JAVAJARDIR}/${jarfile}
.endfor

.include <bsd.port.mk>
