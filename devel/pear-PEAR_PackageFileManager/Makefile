# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	PEAR_PackageFileManager
PORTVERSION=	1.7.0
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class to maintain PEAR packages

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

LATEST_LINK=	pear-${PORTNAME}
OPTIONS_DEFINE=	PEAR_PHP_COMPATINFO PEAR_XML_TREE
PEAR_PHP_COMPATINFO_DESC=	PEAR::PHP_CompatInfo support
PEAR_XML_TREE_DESC=	PEAR::XML_Tree support

PEAR_AUTOINSTALL=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPEAR_PHP_COMPATINFO}
RUN_DEPENDS+=	${PEARDIR}/PHP/CompatInfo.php:${PORTSDIR}/devel/pear-PHP_CompatInfo
.endif

.if ${PORT_OPTIONS:MPEAR_XML_TREE}
RUN_DEPENDS+=	${PEARDIR}/XML/Tree.php:${PORTSDIR}/devel/pear-XML_Tree
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.mk>
