# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	IO_Bit
PORTVERSION=	2.1.1
CATEGORIES=	devel pear
MASTER_SITES=	http://openpear.org/get/ \
		LOCAL
MASTER_SITE_SUBDIR=	tota/${PKGNAMEPREFIX}${PORTNAME}
PKGNAMEPREFIX=	pear-

MAINTAINER=	yoya@awm.jp
COMMENT=	PEAR bit utility

LICENSE=	MIT

BUILD_DEPENDS=	${PEARDIR}/.channels/openpear.org.reg:${PORTSDIR}/devel/pear-channel-openpear
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PHP=	yes
PEAR_CHANNEL=	openpear
PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
