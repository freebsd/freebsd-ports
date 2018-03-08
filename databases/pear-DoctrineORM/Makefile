# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DoctrineORM
PORTVERSION=	2.3.3
CATEGORIES=	databases pear
MASTER_SITES=	http://pear.doctrine-project.org/get/

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Primary package containing the Doctrine ORM

LICENSE=	LGPL21

RUN_DEPENDS=	${PEARDIR}/Doctrine/Common/Version.php:databases/pear-DoctrineCommon@${PHP_FLAVOR} \
	${PEARDIR}/Doctrine/DBAL/Version.php:databases/pear-DoctrineDBAL@${PHP_FLAVOR} \
	${PEARDIR}/Symfony/Component/Console/Application.php:devel/pear-Symfony_Component_Console@${PHP_FLAVOR} \
	${PEARDIR}/Symfony/Component/Yaml/Yaml.php:textproc/pear-Symfony_Component_Yaml@${PHP_FLAVOR}

USES=	pear
PEAR_CHANNEL=	doctrine

.include <bsd.port.mk>
