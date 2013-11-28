# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Structures_DataGrid_DataSource_PDO
PORTVERSION=	0.2.0
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	DataSource driver using PHP Data Objects (PDO) and an SQL query

BUILD_DEPENDS=	${PEARDIR}/Structures/DataGrid/DataSource/Array.php:${PORTSDIR}/databases/pear-Structures_DataGrid_DataSource_Array
RUN_DEPENDS=	${PEARDIR}/Structures/DataGrid/DataSource/Array.php:${PORTSDIR}/databases/pear-Structures_DataGrid_DataSource_Array

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
