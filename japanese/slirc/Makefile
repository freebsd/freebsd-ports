# New ports collection makefile for:	SLirc-ja
# Date created:		6 Jan 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

CATEGORIES=	japanese

MAINTAINER=	knu@FreeBSD.org

MASTERDIR=	${.CURDIR}/../../irc/slirc

MD5_FILE=	${.CURDIR}/distinfo
EXTRA_FILESDIR=	${.CURDIR}/files
EXTRA_PATCHES=	${EXTRA_FILESDIR}/patch-*

SLANG_INCDIR=	${PREFIX}/include/slang
LIB_DEPENDS_LIBSLANG?=	slang.2:${PORTSDIR}/japanese/libslang

MAKE_ARGS_JA=	KANJI="-DKANJI"
PLIST_JA=	""

DOCS=		README.ja

post-patch:
	${CP} ${EXTRA_FILESDIR}/README.ja ${WRKSRC}/

.include "${MASTERDIR}/Makefile"
