# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	PHP_Beautifier
PORTVERSION=	0.1.15
PORTREVISION=	1
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR beautifier for PHP

BUILD_DEPENDS=	${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log
RUN_DEPENDS=	${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log

USE_PHP=	tokenizer bz2
PEAR_AUTOINSTALL=	yes
DEFAULT_PHP_VER=5

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
