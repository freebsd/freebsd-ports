# New ports collection makefile for:	mecab-ipadic
# Date created:		2006-05-07
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	mecab-ipadic
PORTVERSION=	2.7.0
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	${PORTNAME:S/-ipadic//}/${SUB_DIR}
DISTNAME=	${PORTNAME}-${PORTVERSION}-${DISTVERSION}

MAINTAINER=	tota@rtfm.jp
COMMENT=	Japanese Morphological Dictionary for MeCab

BUILD_DEPENDS=	mecab-config:${PORTSDIR}/japanese/mecab

DISTVERSION=	20060408
SUB_DIR=	19691

USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
