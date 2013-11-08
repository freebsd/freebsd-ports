# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	XML_Transformer
PORTVERSION=	1.1.2
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR XML Transformations in PHP

BUILD_DEPENDS=	${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util
RUN_DEPENDS:=	${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
