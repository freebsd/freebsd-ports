# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Structures_DataGrid_DataSource_MDB2
PORTVERSION=	0.1.11
CATEGORIES=	databases www pear

MAINTAINER=	joneum@bsdproject.de
COMMENT=	DataSource driver using PEAR::MDB2 and an SQL query

BUILD_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:devel/pear-Structures_DataGrid \
		${PEARDIR}/MDB2.php:databases/pear-MDB2
RUN_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:devel/pear-Structures_DataGrid \
		${PEARDIR}/MDB2.php:databases/pear-MDB2

USES=	pear
USE_PHP=	mysql
IGNORE_WITH_PHP=	70
NO_ARCH=	yes

.include <bsd.port.mk>
