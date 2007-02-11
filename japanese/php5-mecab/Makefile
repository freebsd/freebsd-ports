# New ports collection makefile for:	php5-mecab
# Date created:		31 Aug 2006
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mecab
PORTVERSION=	0.0.2
CATEGORIES=	japanese
MASTER_SITES=	http://page2.xrea.jp/pub/ \
		http://dist.bsdlab.org/
DISTNAME=	php_mecab-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	A PHP5 extension for MeCab Morphological Analyzer

LIB_DEPENDS=	mecab:${PORTSDIR}/japanese/mecab

BROKEN=		Does not compile
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2007-04-10

USE_PHP=	yes
DEFAULT_PHP_VER=5
USE_PHPEXT=	yes
CONFIGURE_ARGS=	--with-mecab=${LOCALBASE}/bin/mecab-config
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LIBS="${LIBS} ${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}php5-

.include <bsd.port.post.mk>
