# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MDB2_Schema
PORTVERSION=	0.8.6
CATEGORIES=	databases www pear

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PEAR XML based database schema manager

BUILD_DEPENDS=	${PEARDIR}/MDB2.php:databases/pear-MDB2 \
		${PEARDIR}/XML/Parser.php:devel/pear-XML_Parser \
		${PEARDIR}/XML/DTD.php:textproc/pear-XML_DTD \
		${PEARDIR}/XML/Serializer.php:devel/pear-XML_Serializer
RUN_DEPENDS=	${PEARDIR}/MDB2.php:databases/pear-MDB2 \
		${PEARDIR}/XML/Parser.php:devel/pear-XML_Parser \
		${PEARDIR}/XML/DTD.php:textproc/pear-XML_DTD \
		${PEARDIR}/XML/Serializer.php:devel/pear-XML_Serializer

USES=	pear

.include <bsd.port.mk>
