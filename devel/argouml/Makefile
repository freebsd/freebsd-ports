# ex:ts=8
# Ports collection makefile for:	ArgoUML
# Date created:			June 14, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	argouml
PORTVERSION=	0.16.1
CATEGORIES=	devel java
MASTER_SITES=	http://argouml.tigris.org/files/documents/4/0/argouml-${PORTVERSION}/
DISTNAME=	ArgoUML-${PORTVERSION}

MAINTAINER=	philip.reynolds@rfc-networks.ie
COMMENT=	A UML design tool with cognitive support

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3+

SUB_FILES=	argouml.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/argouml.sh ${PREFIX}/bin/argouml
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.jar ${DATADIR}

.include <bsd.port.mk>
