# New ports collection makefile for:   bsh
# Date created:                25 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	bsh
PORTVERSION=	1.2.b5
PORTREVISION=	2
CATEGORIES=	java
MASTER_SITES=	http://www.beanshell.org/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/b/}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	fuyuki@mj.0038.net

USE_JAVA=	1.1+
NO_BUILD=	yes

JAVALIBDIR=	${PREFIX}/share/java/classes
BROKEN=		Checksum error

do-install:
	${MKDIR} ${JAVALIBDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${JAVALIBDIR}/bsh.jar

.include <bsd.port.mk>
