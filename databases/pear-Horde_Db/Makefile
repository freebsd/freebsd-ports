PORTNAME=	Horde_Db
PORTVERSION=	2.4.1
CATEGORIES=	databases www pear

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Database Libraries

OPTIONS_DEFAULT=	MYSQLI
OPTIONS_DEFINE=		MYSQLI PDO
MYSQLI_DESC=		Depend on mysqli PHP extension
PDO_DESC=		Depend on PDO PHP extension

USES=		horde cpe
USE_HORDE_RUN=	Horde_Date \
		Horde_Exception \
		Horde_Support

MYSQLI_USES=	php
MYSQLI_USE=	PHP=mysqli
PDO_USES=	php
PDO_USE=	PHP=pdo

CONFLICTS_INSTALL=	php*-pear-horde-Horde_Db

.include <bsd.port.mk>
