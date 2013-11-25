# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DoctrineCommon
PORTVERSION=	2.3.0
CATEGORIES=	databases pear
MASTER_SITES=	http://pear.doctrine-project.org/get/

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Shared code for Doctrine PHP object relational mapper

LICENSE=	LGPL21

BUILD_DEPENDS=	${PEARDIR}/.channels/pear.doctrine-project.org.reg:${PORTSDIR}/devel/pear-channel-doctrine
RUN_DEPENDS=	${PEARDIR}/.channels/pear.doctrine-project.org.reg:${PORTSDIR}/devel/pear-channel-doctrine

PEAR_CHANNEL=	doctrine
PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
