# Created by: Thomas Abthorpe <thomas@goodking.ca>
# $FreeBSD$

PORTNAME=	Date_Holidays
PORTVERSION=	0.21.8
CATEGORIES=	devel www pear

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PEAR driver based class to calculate holidays

BUILD_DEPENDS=	${PEARDIR}/Date.php:devel/pear-Date \
		${PEARDIR}/XML/Serializer.php:devel/pear-XML_Serializer
RUN_DEPENDS=	${PEARDIR}/Date.php:devel/pear-Date \
		${PEARDIR}/XML/Serializer.php:devel/pear-XML_Serializer

USES=		pear

OPTIONS_DEFINE=	PEAR_CONSOLE_GETARGS
PEAR_CONSOLE_GETARGS_DESC=	Console::Getargs support

PEAR_CONSOLE_GETARGS_BUILD_DEPENDS=${PEARDIR}/Console/Getargs.php:devel/pear-Console_Getargs

.include <bsd.port.mk>
