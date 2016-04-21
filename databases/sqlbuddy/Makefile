# Created by: Chenguang LI
# $FreeBSD$

PORTNAME=	sqlbuddy
PORTVERSION=	1.3.3
PORTREVISION=	3
CATEGORIES=	databases www

MAINTAINER=	horus.li@gmail.com
COMMENT=	Web based MySQL administration with a set of PHP scripts

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	Does not build

USE_GITHUB=	yes
GH_ACCOUNT=	deliciousbrains
GH_TAGNAME=	b2cdc2b

NO_BUILD=	yes

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
	@cd ${WRKSRC} && ${CP} -R src/* ${STAGEDIR}${WWWDIR} && ${CP} LICENSE README.md ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
