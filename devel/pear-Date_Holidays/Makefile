# Created by: Thomas Abthorpe <thomas@goodking.ca>

PORTNAME=	Date_Holidays
PORTVERSION=	0.21.8
PORTREVISION=	1
CATEGORIES=	devel www pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEAR driver based class to calculate holidays

LICENSE=	PHP301

BUILD_DEPENDS=	${PEARDIR}/XML/Serializer.php:devel/pear-XML_Serializer@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/XML/Serializer.php:devel/pear-XML_Serializer@${PHP_FLAVOR}

USES=		pear

USE_GITHUB=	yes
GH_ACCOUNT=	pear
GH_TAGNAME=	a3fc96f

NO_ARCH=	yes

OPTIONS_DEFINE=	PEAR_CONSOLE_GETARGS
PEAR_CONSOLE_GETARGS_DESC=	Console::Getargs support

PEAR_CONSOLE_GETARGS_BUILD_DEPENDS=${PEARDIR}/Console/Getargs.php:devel/pear-Console_Getargs@${PHP_FLAVOR}

.include <bsd.port.mk>
