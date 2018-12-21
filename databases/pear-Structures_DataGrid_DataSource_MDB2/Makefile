# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Structures_DataGrid_DataSource_MDB2
PORTVERSION=	0.1.11
CATEGORIES=	databases www pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	DataSource driver using PEAR::MDB2 and an SQL query

LICENSE=	BSD2CLAUSE

IGNORE_WITH_PHP=	56

BUILD_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:devel/pear-Structures_DataGrid@${PHP_FLAVOR} \
		${PEARDIR}/MDB2.php:databases/pear-MDB2@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:devel/pear-Structures_DataGrid@${PHP_FLAVOR} \
		${PEARDIR}/MDB2.php:databases/pear-MDB2@${PHP_FLAVOR}

USES=	pear
USE_PHP=	mysqli

NO_ARCH=	yes

.include <bsd.port.mk>
