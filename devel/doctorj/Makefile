# Created by: Michael L. Hostbaek <mich@freebsdcluster.org>
# $FreeBSD$

PORTNAME=	doctorj
PORTVERSION=	5.1.2
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for analyzing Java code and documentation

USE_JAVA=	yes
USE_ANT=	yes

ALL_TARGET=	jarfile

PLIST_FILES=	%%JAVAJARDIR%%/doctorj.jar man/man1/doctorj.1.gz

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/share/doctorj/doctorj.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/doctorj.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
