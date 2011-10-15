# New ports collection makefile for:	maven-wrapper
# Date created:		2011-09-19
# Whom:			Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	maven-wrapper
PORTVERSION=	1
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Wrapper script for the various installations of Maven

NO_BUILD=	yes
SUB_FILES=	mvn.sh
SUB_LIST=	CAT=${CAT} FIND=${FIND} TAIL=${TAIL}

do-fecth:
	@${DO_NADA}

do-install:
	${MKDIR} "${PREFIX}/etc/maven-wrapper/instances.d"
	${INSTALL_SCRIPT} "${WRKDIR}/mvn.sh" "${PREFIX}/bin/mvn"

.include <bsd.port.mk>
