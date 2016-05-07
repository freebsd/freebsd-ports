# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Structures_DataGrid_DataSource_DBTable
PORTVERSION=	0.1.7
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	DataSource driver using PEAR::DB_Table

BUILD_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:devel/pear-Structures_DataGrid \
		${PEARDIR}/DB/Table.php:databases/pear-DB_Table
RUN_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:devel/pear-Structures_DataGrid \
		${PEARDIR}/DB/Table.php:databases/pear-DB_Table

USES=	pear
USE_PHP=	mysql
IGNORE_WITH_PHP=	70
NO_ARCH=	yes

.include <bsd.port.mk>
