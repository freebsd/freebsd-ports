# Created by: Chenguang LI
# $FreeBSD$

PORTNAME=	sqlbuddy
PORTVERSION=	1.3.3
PORTREVISION=	2
CATEGORIES=	databases www
MASTER_SITES=	http://www.sqlbuddy.com/download/
DISTNAME=	${PORTNAME}_1_3_3

MAINTAINER=	horus.li@gmail.com
COMMENT=	Web based MySQL administration with a set of PHP scripts

USES=		zip
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PHP=	ctype pcre session mysql
WANT_PHP_WEB=	yes

PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "NOTE:"
	@${ECHO_MSG} "This port assumes you have already installed a mysql database, "
	@${ECHO_MSG} "and you want to use SQL Buddy to manage the server."
	@${ECHO_MSG} "If you are planning to install it/them on this machine later, "
	@${ECHO_MSG} "you can find it/them at ${PORTSDIR}/databases."
	@${ECHO_MSG} ""

do-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Installing SQL Buddy under ${WWWDIR}/"
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${CP} -R * ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
