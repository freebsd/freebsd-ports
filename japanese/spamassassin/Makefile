# Created by: TAOKA Fumiyoshi
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	japanese mail perl5
PKGNAMEPREFIX=	ja-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SpamAssassin with patches to handle multibyte character

LICENSE=	APACHE20

BROKEN=		patch does not apply
DEPRECATED=	does not build
EXPIRATION_DATE=2018-12-31

MASTERDIR=	${.CURDIR}/../../mail/spamassassin

BUILD_DEPENDS=	ja-p5-MeCab>=0.98:japanese/p5-MeCab

CONFLICTS=	spamassassin-[0-9]*

EXTRA_PATCHES=	${.CURDIR}/files/spamassassin-ja.patch

PKGMESSAGE=	${.CURDIR}/pkg-message
PLIST=		${WRKDIR}/pkg-plist

TOKENIZER_PRE=	tokenizer.pre

PLIST_SUB+=	TOKENIZER_PRE=${TOKENIZER_PRE}

pre-install:
	@${CAT} ${EXTRA_PATCHES:S/.patch/.plist/} > ${PLIST}
	@${CAT} ${PKGDIR}/pkg-plist >> ${PLIST}

post-install::
	${INSTALL_DATA} ${.CURDIR}/files/${TOKENIZER_PRE} ${STAGEDIR}${ETCDIR}/${TOKENIZER_PRE}.sample

.include "${MASTERDIR}/Makefile"
