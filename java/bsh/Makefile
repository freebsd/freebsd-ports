# New ports collection makefile for:   bsh
# Date created:                25 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	bsh
PORTVERSION=	1.2.b3
CATEGORIES=	java
MASTER_SITES=	http://www.beanshell.org/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/b/}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	fuyuki@mj.0038.net

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

NO_BUILD=	yes

JAVALIBDIR=	${PREFIX}/share/java/classes

do-install:
	${MKDIR} ${JAVALIBDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${JAVALIBDIR}/bsh.jar

.include <bsd.port.mk>
