# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PHP_Depend
PORTVERSION=	1.1.0
CATEGORIES=	devel pear
MASTER_SITES=	http://pear.pdepend.org/get/
PKGNAMEPREFIX=	pear-

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP_Depend design quality metrics for PHP packages

LICENSE=	BSD

BUILD_DEPENDS=	pear>=1.6.0:${PORTSDIR}/devel/pear \
		${PEARDIR}/.channels/pear.pdepend.org.reg:${PORTSDIR}/devel/pear-channel-pdepend
RUN_DEPENDS=	pear>=1.6.0:${PORTSDIR}/devel/pear \
		${PEARDIR}/.channels/pear.pdepend.org.reg:${PORTSDIR}/devel/pear-channel-pdepend

PEAR_CHANNEL=	pdepend
PEAR_AUTOINSTALL=	yes
USE_PHP=	dom tokenizer simplexml

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
