# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Structures_DataGrid_DataSource_DBTable
PORTVERSION=	0.1.7
CATEGORIES=	databases www pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	DataSource driver using PEAR::DB_Table

BUILD_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:devel/pear-Structures_DataGrid@${PHP_FLAVOR} \
		${PEARDIR}/DB/Table.php:databases/pear-DB_Table@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:devel/pear-Structures_DataGrid@${PHP_FLAVOR} \
		${PEARDIR}/DB/Table.php:databases/pear-DB_Table@${PHP_FLAVOR}

USES=	pear
USE_PHP=	mysql
IGNORE_WITH_PHP=	70 71 72
NO_ARCH=	yes

.include <bsd.port.mk>
