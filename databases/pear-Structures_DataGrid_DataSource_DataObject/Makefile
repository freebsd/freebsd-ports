# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Structures_DataGrid_DataSource_DataObject
PORTVERSION=	0.2.1
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	DataSource driver using PEAR::DB_DataObject

BUILD_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:${PORTSDIR}/devel/pear-Structures_DataGrid \
		${PEARDIR}/DB/DataObject.php:${PORTSDIR}/databases/pear-DB_DataObject
RUN_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:${PORTSDIR}/devel/pear-Structures_DataGrid \
		${PEARDIR}/DB/DataObject.php:${PORTSDIR}/databases/pear-DB_DataObject

USE_PHP=	mysql
PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
