PORTNAME=	PhpDocumentor
PORTVERSION=	1.4.4
CATEGORIES=	devel www pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides automatic documenting of php-api from the source

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pear

NO_ARCH=	yes

CONFLICTS_INSTALL=	pear-PHPDoc

OPTIONS_DEFINE=	XML_BEAUTIFIER
XML_BEAUTIFIER_DESC=	XML_Beautifier support

XML_BEAUTIFIER_RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}XML_Beautifier>=1.1:textproc/pear-XML_Beautifier@${PHP_FLAVOR}

.include <bsd.port.mk>
