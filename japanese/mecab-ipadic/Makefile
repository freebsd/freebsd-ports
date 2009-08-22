# New ports collection makefile for:	mecab-ipadic
# Date created:		2006-05-07
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	mecab
DISTVERSION=	2.7.0-20070801
CATEGORIES=	japanese textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-ipadic/2.7.0-20070801
PKGNAMESUFFIX=	-ipadic
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}

MAINTAINER=	yasu@utahime.org
COMMENT=	Japanese Morphological Dictionary for MeCab

BUILD_DEPENDS=	ja-mecab>=0.94:${PORTSDIR}/japanese/mecab

USE_PERL5_BUILD=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-dicdir=${PREFIX}/lib/mecab/dic/ipadic

# Set charset (euc-jp/shift_jis/utf-8)
.if defined(WITH_CHARSET)
CONFIGURE_ARGS+=	--with-charset=${WITH_CHARSET}
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_CHARSET=charset  sets default charset (euc-jp/shift_jis/utf-8)"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
