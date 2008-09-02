# New ports collection makefile for:   SQL Buddy
# Date created:        17 August 2008
# Whom:                Chenguang LI
#
# $FreeBSD$
#

PORTNAME=	sqlbuddy
PORTVERSION=	1.2.9
CATEGORIES=	databases www
MASTER_SITES=	http://www.sqlbuddy.com/download/
DISTNAME=	${PORTNAME}

MAINTAINER=	horus.li@gmail.com
COMMENT=	Web based MySQL administration with a set of PHP scripts

USE_ZIP=	yes
NO_BUILD=	yes

USE_PHP=	ctype mysql pcre session
WANT_PHP_WEB=	yes

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "NOTE:"
	@${ECHO_MSG} "This port suppose you have already installed MySQL, "
	@${ECHO_MSG} "and you want to use SQL Buddy to manage the server."
	@${ECHO_MSG} "If you are planning to install MySQL on this machine later, "
	@${ECHO_MSG} "you can find it at ${PORTSDIR}/databases."
	@${ECHO_MSG} ""

do-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Installing SQL Buddy under ${WWWDIR}/"
	@${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${CP} -R * ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
