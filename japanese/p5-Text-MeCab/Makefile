# New ports collection makefile for:	p5-TexT-MeCab
# Date created:		30 July 2006
# Whom:			TAOKA Fumiyoshi <fmysh@iijmio-mail.jp>
#
# $FreeBSD$
#

PORTNAME=		Text-MeCab
PORTVERSION=		0.20004
CATEGORIES=		japanese textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text

MAINTAINER=		fmysh@iijmio-mail.jp
COMMENT=		Alternate Interface To libmecab

LIB_DEPENDS=		mecab.1:${PORTSDIR}/japanese/mecab

MAN3=			Text::MeCab.3 \
			Text::MeCab::Dict.3 \
			Text::MeCab::Node.3

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	</dev/null

# dictionary encoding (euc-jp, shift_jis, utf-8)
ENCODING?=	utf-8

post-patch:
	@${REINPLACE_CMD} -e "/default_encoding = /s/utf-8/${ENCODING}/" \
		${WRKSRC}/tools/probe_mecab.pl

	# To prevent CCFLAGS value from being overwritten by the ports system
	@${REINPLACE_CMD} -e "s|CCFLAGS|INC|g" ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
