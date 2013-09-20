# Created by: Chenguang LI
# $FreeBSD$

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

OPTIONS_DEFINE=	MYSQL SQLITE
OPTIONS_DEFAULT=	SQLITE

SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif
.if ${PORT_OPTIONS:MSQLITE}
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

.include <bsd.port.mk>
