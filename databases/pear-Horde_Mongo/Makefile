# $FreeBSD$

PORTNAME=	Horde_Mongo
PORTVERSION=	1.0.2
CATEGORIES=	databases www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Mongo Configuration

RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/mongo.so:${PORTSDIR}/databases/pecl-mongo

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
