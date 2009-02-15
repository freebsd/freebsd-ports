# New ports collection makefile for:	php5-mecab
# Date created:		31 Aug 2006
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mecab
PORTVERSION=	0.4.0
CATEGORIES=	japanese
MASTER_SITES=	http://www.opendogs.org/pub/ \
		http://dist.bsdlab.org/
DISTNAME=	php_mecab-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	A PHP5 extension for MeCab Morphological Analyzer

LIB_DEPENDS=	mecab:${PORTSDIR}/japanese/mecab

USE_PHP=	yes
DEFAULT_PHP_VER=5
USE_PHPEXT=	yes
CONFIGURE_ARGS=	--with-mecab=${LOCALBASE}/bin/mecab-config
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LIBS="${LIBS} ${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}php5-

.include <bsd.port.post.mk>
