# New ports collection makefile for:	mecab-ipadic
# Date created:		2006-05-07
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	mecab-ipadic
PORTVERSION=	2.7.0
PORTREVISION=	2
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/-ipadic//}
DISTNAME=	${PORTNAME}-${PORTVERSION}-${DISTVERSION}

MAINTAINER=	tota@rtfm.jp
COMMENT=	Japanese Morphological Dictionary for MeCab

BUILD_DEPENDS=	ja-mecab>=0.94:${PORTSDIR}/japanese/mecab

DISTVERSION=	20060707

USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes

# Set charset (euc-jp/sjis_jis/utf-8)
.if defined(WITH_CHARSET)
CONFIGURE_ARGS=	--with-charset=${WITH_CHARSET}
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_CHARSET=charset  sets default charset (euc-jp/sjis_jis/utf-8)"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
