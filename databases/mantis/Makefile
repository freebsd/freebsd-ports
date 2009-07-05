# New ports collection makefile for:   mantis
# Date created:        6 December 2002
# Whom:                Sebastien Gioria <gioria@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	mantis
PORTVERSION=	1.1.8
CATEGORIES=	databases www
MASTER_SITES=	SF/mantisbt
DISTNAME=	mantisbt-${PORTVERSION}

MAINTAINER=	dan@langille.org
COMMENT=	A bug tracking system written in PHP

NO_BUILD=	yes
USE_MYSQL=	yes
USE_PHP=	pcre

SUB_FILES=	pkg-message

PLIST_SUB+=	WWWDIR_REL=${WWWDIR_REL}

.ifdef(MANTISDIR)
WWWDIR=	${MANTISDIR}
DMSG=	"Usage of MANTISDIR is depreciated and will be dropped in future versions, please use WWWDIR instead."
.endif

pre-everything::
	@${ECHO_CMD} ${DMSG}

do-install:
	@${ECHO} "Installing in WWWDIR: ${WWWDIR}"
	${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC}/* ${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
