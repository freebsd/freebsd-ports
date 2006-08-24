# New ports collection makefile for:   mantis
# Date created:        6 December 2002
# Whom:                Sebastien Gioria <gioria@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	mantis
PORTVERSION=	1.0.5
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mantisbt
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	dan@langille.org
COMMENT=	A bug tracking system written in PHP

NO_BUILD=	yes
USE_MYSQL=	yes
USE_APACHE=	yes
USE_PHP=	yes

MANTISDIR?=	www/${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	MANTISDIR=${MANTISDIR}

PLIST_SUB=	MANTISDIR=${MANTISDIR}

do-install:
	@${ECHO} "Installing in ${PREFIX}/${MANTISDIR}"
	${MKDIR} ${PREFIX}/${MANTISDIR}
	${CP} -R ${WRKSRC}/* ${PREFIX}/${MANTISDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${MANTISDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
