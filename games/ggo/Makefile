# New ports collection makefile for:   gGo
# Date created:		12 February 2005
# Whom:			jonc@chen.org.nz
#
# $FreeBSD$
#

PORTNAME=	ggo
PORTVERSION=	1.0
CATEGORIES=	games java
MASTER_SITES=	http://www.pandanet.co.jp/java/gGo/download/
DISTNAME=	gGo-${PORTVERSION}

MAINTAINER=	jonc@chen.org.nz
COMMENT=	PandaNet's IGS Client, GNU Go Client and SGF Editor

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
RESTRICTED=	Redistribution is restricted
STRIP=
SUB_FILES=	ggo.sh

post-extract:
	@cd ${WRKDIR} && ${TAR} xf gGo.ss

do-install:
	${MKDIR} ${DATADIR}
	for JAR in ${WRKDIR}/usr/local/gGo/lib/*.jar ${WRKDIR}/usr/local/gGo/lib/*.zip ; \
	do \
		${INSTALL_DATA} $${JAR} ${DATADIR}; \
	done
	${INSTALL_SCRIPT} ${WRKDIR}/ggo.sh ${PREFIX}/bin/ggo

.include <bsd.port.mk>
