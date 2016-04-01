# Created by: Gerrit Beine (<gerrit.beine@gmx.de>)
# $FreeBSD$

PORTNAME=	PhpDocumentor
PORTVERSION=	1.4.4
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Provides automatic documenting of php-api from the source

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:devel/pear
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	pear-PHPDoc-[0-9]*

USES=	pear
OPTIONS_DEFINE=	XML_BEAUTIFIER
XML_BEAUTIFIER_DESC=	XML_Beautifier support

XML_BEAUTIFIER_RUN_DEPENDS=	${PEARDIR}/XML/Beautifier.php:textproc/pear-XML_Beautifier

post-extract:
.for dir in ${DUMMYDIRS}
	${TOUCH} ${WRKSRC}/${dir}/.peardummy
.endfor

.include <bsd.port.mk>
