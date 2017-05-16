# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Structures_DataGrid_DataSource_DBQuery
PORTVERSION=	0.1.11
CATEGORIES=	databases www pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	DataSource driver using PEAR::DB and an SQL query

BUILD_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:devel/pear-Structures_DataGrid \
		${PEARDIR}/DB.php:databases/pear-DB
RUN_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:devel/pear-Structures_DataGrid \
		${PEARDIR}/DB.php:databases/pear-DB

USES=	pear
USE_PHP=	mysql
IGNORE_WITH_PHP=	70 71
NO_ARCH=	yes

.include <bsd.port.mk>
