# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	IO_SWF
PORTVERSION=	2.2.6
CATEGORIES=	graphics www pear
MASTER_SITES=	http://openpear.org/get/ \
		LOCAL/tota/${PKGNAMEPREFIX}${PORTNAME}
PKGNAMEPREFIX=	pear-

MAINTAINER=	yoya@awm.jp
COMMENT=	PEAR library for reading/writing SWF binary

LICENSE=	MIT

RUN_DEPENDS=	pear-IO_Bit>0:${PORTSDIR}/devel/pear-IO_Bit \
		${PEARDIR}/.channels/openpear.org.reg:${PORTSDIR}/devel/pear-channel-openpear

USE_PHP=	yes
PEAR_CHANNEL=	openpear
USES=	pear

.include <bsd.port.mk>
