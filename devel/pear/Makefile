# Ports collection makefile for:  pear
# Date created:			  Sat Nov 10, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	pear
PORTVERSION=	4.1.0
CATEGORIES=	devel www
MASTER_SITES=	ftp://ftp.horde.org/pub/horde/tarballs/
PKGNAMESUFFIX=	-devel

MAINTAINER=	thierry@pompo.net

RUN_DEPENDS=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

USE_BZIP2=	yes
NO_BUILD=	yes

LPHP_LIB?=	lib/php

PLIST_SUB=	PEARDIR=${LPHP_LIB}

PEARDIR=	${LOCALBASE}/${LPHP_LIB}

FORBIDDEN=	"This module is now part of mod_php4 as of 4.1.0"

do-install:
	@${ECHO} "===> Backup the original PEAR from mod_php4 into ${PEARDIR}.DIST_PHP ..."
	${MV}	${PEARDIR} ${PEARDIR}.DIST_PHP
	@${ECHO} "===> Installing the new PEAR ..."
	${MKDIR} ${PEARDIR}
	${CP} -Rp ${WRKSRC}/* ${PEARDIR}

post-install:
	@${ECHO} "*****************************************************************"
	@${ECHO} ""
	@${ECHO} "The new PEAR has replaced your original distribution."
	@${ECHO} "No recompilation or restarting of the server is necessary."
	@${ECHO} ""
	@${ECHO} "*****************************************************************"

.include <bsd.port.mk>
