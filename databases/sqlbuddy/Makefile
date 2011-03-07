# New ports collection makefile for:   SQL Buddy
# Date created:        17 August 2008
# Whom:                Chenguang LI
#
# $FreeBSD$
#

PORTNAME=	sqlbuddy
PORTVERSION=	1.3.3
CATEGORIES=	databases www
MASTER_SITES=	http://www.sqlbuddy.com/download/
DISTNAME=	${PORTNAME}_1_3_3

MAINTAINER=	horus.li@gmail.com
COMMENT=	Web based MySQL administration with a set of PHP scripts

USE_ZIP=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PHP=	ctype pcre session
WANT_PHP_WEB=	yes

OPTIONS+=	MYSQL  "MySQL support" on \
		SQLITE "SQLite support" off

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_PHP+=	mysql
.endif
.if defined(WITH_SQLITE)
USE_PHP+=	sqlite
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "NOTE:"
	@${ECHO_MSG} "This port suppose you have already installed one or both of these databases supported, "
	@${ECHO_MSG} "and you want to use SQL Buddy to manage the server."
	@${ECHO_MSG} "If you are planning to install it/them on this machine later, "
	@${ECHO_MSG} "you can find it/them at ${PORTSDIR}/databases."
	@${ECHO_MSG} ""

do-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Installing SQL Buddy under ${WWWDIR}/"
	@${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${CP} -R * ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
