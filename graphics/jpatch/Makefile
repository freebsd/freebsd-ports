# ex:ts=8
# Ports collection makefile for:	jpatch
# Date created:			Jun 30, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jpatch
PORTVERSION=	0.3.b1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.b/beta/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A spline based 3D modeling tool

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar \
		bin/jpatch

SUB_FILES=	jpatch.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/jpatch.jar ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/jpatch.sh ${PREFIX}/bin/jpatch

.include <bsd.port.mk>
