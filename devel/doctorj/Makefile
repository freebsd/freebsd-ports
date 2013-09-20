# Created by: Michael L. Hostbaek <mich@freebsdcluster.org>
# $FreeBSD$

PORTNAME=	doctorj
PORTVERSION=	5.1.2
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for analyzing Java code and documentation

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes

ALL_TARGET=	jarfile

MAN1=		doctorj.1
PLIST_FILES=	%%JAVAJARDIR%%/doctorj.jar

NO_STAGE=	yes
do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/doctorj.jar..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/share/doctorj/doctorj.jar ${JAVAJARDIR}/
	@${ECHO_MSG} -n ">> Installing MANPAGE ..."
	@${INSTALL_MAN} ${WRKSRC}/doc/doctorj.1 ${MAN1PREFIX}/man/man1
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
