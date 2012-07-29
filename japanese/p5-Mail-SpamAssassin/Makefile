# New ports collection makefile for:	ja-p5-Mail-SpamAssassin
# Date created:				Jun 24 2007
# Whom:					TAOKA Fumiyoshi
#
# $FreeBSD$
#

PORTREVISION=	2
CATEGORIES=	japanese mail perl5
PKGNAMEPREFIX=	ja-p5-

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	SpamAssassin with patches to handle multibyte character

LICENSE=	AL2

MASTERDIR=	${.CURDIR}/../../mail/p5-Mail-SpamAssassin

RUN_DEPENDS+=	ja-p5-MeCab>=0.98:${PORTSDIR}/japanese/p5-MeCab

CONFLICTS=	p5-Mail-SpamAssassin-[0-9]*

EXTRA_PATCHES=	${.CURDIR}/files/spamassassin-3.3.2-ja-1.patch

PKGMESSAGE=	${.CURDIR}/pkg-message
PLIST=		${WRKDIR}/pkg-plist

TOKENIZER_PRE=	tokenizer.pre

PLIST_SUB+=	TOKENIZER_PRE=${TOKENIZER_PRE}

MAN3=		Mail::SpamAssassin::Util::Charset.3 \
		Mail::SpamAssassin::Plugin::Tokenizer::MeCab.3 \
		Mail::SpamAssassin::Plugin::Tokenizer.3 \
		Mail::SpamAssassin::Plugin::Tokenizer::SimpleJA.3

pre-install:
	@${CAT} ${EXTRA_PATCHES:S/.patch/.plist/} > ${PLIST}
	@${CAT} ${PKGDIR}/pkg-plist >> ${PLIST}

post-install::
	@${CP} ${.CURDIR}/files/${TOKENIZER_PRE} ${ETCDIR}/${TOKENIZER_PRE}.sample
	@[ -f ${ETCDIR}/${TOKENIZER_PRE} ] || \
		${INSTALL_DATA} ${ETCDIR}/${TOKENIZER_PRE}.sample \
			${ETCDIR}/${TOKENIZER_PRE}

.include "${MASTERDIR}/Makefile"
