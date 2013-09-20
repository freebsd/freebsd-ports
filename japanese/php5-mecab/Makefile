# $FreeBSD$

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
USE_PHPEXT=	yes
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5
CONFIGURE_ARGS=	--with-mecab=${LOCALBASE}/bin/mecab-config
CONFIGURE_ENV=	LIBS="${LIBS} ${PTHREAD_LIBS}"
CFLAGS+=	${PTHREAD_CFLAGS}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}php5-

.include <bsd.port.post.mk>
