# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	zookeeper
PORTVERSION=	0.2.1
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	gslin@gslin.org
COMMENT=	PHP extension for interfacing with Apache ZooKeeper

LIB_DEPENDS=	zookeeper_st:${PORTSDIR}/devel/zookeeper

USE_PHP=	session
USE_PHP_BUILD=	session
USE_PHPEXT=	yes

NO_STAGE=	yes
post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/zookeeper-api.php ${DATADIR}/

.include <bsd.port.mk>
