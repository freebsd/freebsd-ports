# $FreeBSD$

PORTNAME=	Horde_Db
PORTVERSION=	2.1.1
CATEGORIES=	databases www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Database Libraries

OPTIONS_DEFAULT=	MYSQL
OPTIONS_DEFINE=		MYSQL MYSQLI PDO
MYSQL_DESC=		Depend on mysql PHP extension
MYSQLI_DESC=		Depend on mysqli PHP extension
PDO_DESC=		Depend on PDO PHP extension

USE_HORDE_RUN=	Horde_Date \
		Horde_Exception \
		Horde_Support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MMYSQLI}
USE_PHP+=	mysqli
.endif

.if ${PORT_OPTIONS:MPDO}
USE_PHP+=	pdo
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
