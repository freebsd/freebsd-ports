PORTNAME=	PEAR_Info
PORTVERSION=	1.9.2
PORTREVISION=	2
CATEGORIES=	devel www pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Show Information about your PEAR install and its packages

LICENSE=	PHP301

RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Console_Getargs>=1.3.3:devel/pear-Console_Getargs@${PHP_FLAVOR}

USES=		pear
USE_PHP=	pcre

NO_ARCH=	yes

OPTIONS_DEFINE=	PHPUNIT
OPTIONS_DEFAULT=PHPUNIT
PHPUNIT_DESC=	PEAR::PHPUnit support

PHPUNIT_RUN_DEPENDS=	phpunit6${PHP_PKGNAMESUFFIX}>=3.1.4:devel/phpunit6@${PHP_FLAVOR}

.include <bsd.port.mk>
