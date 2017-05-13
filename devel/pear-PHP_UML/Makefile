# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	PHP_UML
PORTVERSION=	1.6.2
CATEGORIES=	devel

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PEAR Class to Create UML Representation of PHP Code

LICENSE=	LGPL3

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:devel/pear \
		${PEARDIR}/Console/CommandLine.php:devel/pear-Console_CommandLine
RUN_DEPENDS=	${PEARDIR}/PEAR.php:devel/pear

BROKEN_powerpc64=	fails to package: Signal 11

USES=		pear
USE_PHP=	spl xsl

.include <bsd.port.mk>
