# New ports collection makefile for:	taskstep
# Date created:		2006-06-19
# Whom:			Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	taskstep
PORTVERSION=	0.6
CATEGORIES=	deskutils www
MASTER_SITES=	http://taskstep.cunningtitle.co.uk/releases/
DISTNAME=	${PORTNAME}-06

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Web based to-do list manager written in php

NO_BUILD=	YES
USE_PHP=	mysql
WANT_PHP_WEB=	YES
USE_ZIP=	YES
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

TASKSTEP?=	www/taskstep
PLIST_SUB+=	TASKSTEP=${TASKSTEP}
SUB_LIST+=	TASKSTEP=${TASKSTEP}
SUB_FILES=	pkg-message

pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD} "Set, if you need, relative to PREFIX (default: /usr/local):"
	@${ECHO_CMD} "TASKSTEP=${TASKSTEP} (default: www/taskstep)"
	@${ECHO_CMD}

do-install:
	@${MKDIR} ${PREFIX}/${TASKSTEP}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${TASKSTEP}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${TASKSTEP}
	@${CHMOD} -R 755 ${PREFIX}/${TASKSTEP}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
