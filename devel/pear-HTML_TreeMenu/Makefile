# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	HTML_TreeMenu
PORTVERSION=	1.2.2
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Provides an API to create a HTML tree

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

PEAR_AUTOINSTALL=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
