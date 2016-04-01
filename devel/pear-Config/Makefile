# Created by: Alex Miller (<asm@asm.kiev.ua>)
# $FreeBSD$

PORTNAME=	Config
PORTVERSION=	1.10.12
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Your configurations swiss-army knife

OPTIONS_DEFINE=	PEAR_XML_PARSER PEAR_XML_UTIL
PEAR_XML_PARSER_DESC=	PEAR::XML_Parser support
PEAR_XML_UTIL_DESC=	PEAR::XML_Util support

USES=	pear

PEAR_XML_PARSER_RUN_DEPENDS=	${PEARDIR}/XML/Parser.php:devel/pear-XML_Parser
PEAR_XML_UTIL_RUN_DEPENDS=	${PEARDIR}/XML/Util.php:devel/pear-XML_Util

.include <bsd.port.mk>
