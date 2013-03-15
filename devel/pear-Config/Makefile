# Created by: Alex Miller (<asm@asm.kiev.ua>)
# $FreeBSD$

PORTNAME=	Config
PORTVERSION=	1.10.12
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Your configurations swiss-army knife

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

LATEST_LINK=	pear-${PORTNAME}
OPTIONS_DEFINE=	PEAR_XML_PARSER PEAR_XML_UTIL
PEAR_XML_PARSER_DESC=	PEAR::XML_Parser support
PEAR_XML_UTIL_DESC=	PEAR::XML_Util support

PEAR_AUTOINSTALL=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPEAR_XML_PARSER}
RUN_DEPENDS+=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser
.endif

.if ${PORT_OPTIONS:MPEAR_XML_UTIL}
RUN_DEPENDS+=	${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.mk>
