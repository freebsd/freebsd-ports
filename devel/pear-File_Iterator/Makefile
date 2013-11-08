# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	File_Iterator
PORTVERSION=	1.3.3
CATEGORIES=	devel www pear
MASTER_SITES=	http://pear.phpunit.de/get/
PKGNAMEPREFIX=	pear-

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PEAR FileIterator implementation

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/.channels/pear.phpunit.de.reg:${PORTSDIR}/devel/pear-channel-phpunit
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/.channels/pear.phpunit.de.reg:${PORTSDIR}/devel/pear-channel-phpunit

PEAR_CHANNEL=	phpunit
PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
