# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DoctrineORM
PORTVERSION=	2.3.3
CATEGORIES=	databases pear
MASTER_SITES=	http://pear.doctrine-project.org/get/

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Primary package containing the Doctrine ORM

LICENSE=	LGPL21

BUILD_DEPENDS=	${PEARDIR}/.channels/pear.doctrine-project.org.reg:devel/pear-channel-doctrine
RUN_DEPENDS=	${PEARDIR}/.channels/pear.doctrine-project.org.reg:devel/pear-channel-doctrine \
	${PEARDIR}/Doctrine/Common/Version.php:databases/pear-DoctrineCommon \
	${PEARDIR}/Doctrine/DBAL/Version.php:databases/pear-DoctrineDBAL \
	${PEARDIR}/Symfony/Component/Console/Application.php:devel/pear-Symfony_Component_Console \
	${PEARDIR}/Symfony/Component/Yaml/Yaml.php:textproc/pear-Symfony_Component_Yaml

USES=	pear
PEAR_CHANNEL=	doctrine

.include <bsd.port.mk>
