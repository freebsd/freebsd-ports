# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MDB2_Schema
PORTVERSION=	0.8.5
CATEGORIES=	databases www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR XML based database schema manager

BUILD_DEPENDS=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2 \
		${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser \
		${PEARDIR}/XML/DTD.php:${PORTSDIR}/textproc/pear-XML_DTD \
		${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer
RUN_DEPENDS=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2 \
		${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser \
		${PEARDIR}/XML/DTD.php:${PORTSDIR}/textproc/pear-XML_DTD \
		${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer

USES=	pear

.include <bsd.port.mk>
