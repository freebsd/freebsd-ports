# $FreeBSD$

PORTNAME=	mecab
PORTVERSION=	0.5.0
CATEGORIES=	japanese
MASTER_SITES=	http://github.com/downloads/rsky/php-${PORTNAME}/
DISTNAME=	php-mecab-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	A PHP5 extension for MeCab Morphological Analyzer

LIB_DEPENDS=	mecab:${PORTSDIR}/japanese/mecab

USE_PHP=	yes
USE_PHPEXT=	yes
CONFIGURE_ARGS=	--with-mecab=${LOCALBASE}/bin/mecab-config

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}php5-

.include <bsd.port.post.mk>
