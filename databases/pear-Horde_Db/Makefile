# Ports collection makefile for:  pear-Horde_Db
# Date created:			  7 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	Horde_Db
PORTVERSION=	1.1.1
CATEGORIES=	databases www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Database Libraries

OPTIONS=	MYSQL "Depend on mysql PHP extension" On \
		MYSQLI "Depend on mysqli PHP extension" Off \
		PDO "Depend on PDO PHP extension" Off

USE_HORDE_RUN=	Horde_Date Horde_Exception Horde_Support

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_MYSQLI)
USE_PHP+=	mysqli
.endif

.if defined(WITH_PDO)
USE_PHP+=	pdo
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
