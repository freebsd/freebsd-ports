# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MDB2_Schema
PORTVERSION=	0.8.5
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR XML based database schema manager

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2 \
		${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser \
		${PEARDIR}/XML/DTD.php:${PORTSDIR}/textproc/pear-XML_DTD \
		${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2 \
		${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser \
		${PEARDIR}/XML/DTD.php:${PORTSDIR}/textproc/pear-XML_DTD \
		${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
