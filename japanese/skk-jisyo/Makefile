# New ports collection makefile for:	skk-jisyo
# Version required:	9.6
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	skk9.6
PKGNAME=	ja-skk-jisyo${SKKJISYO_SIZE}-9.6
CATEGORIES=	japanese
MASTER_SITES=	ftp://skk.kuis.kyoto-u.ac.jp/skk/9.6/

MAINTAINER=	matusita@jp.freebsd.org

.if !defined(SKKJISYO_SIZE)
SKKJISYO_SIZE=	L
.else
.if ${SKKJISYO_SIZE} != L && ${SKKJISYO_SIZE} != M && ${SKKJISYO_SIZE} != S
SKKJISYO_SIZE_INVALID=	yes
.endif
.endif
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}

WRKSRC=		${WRKDIR}/skk-9.6
GNU_CONFIGURE=	yes
NO_BUILD=	yes
INSTALL_TARGET=	install-jisyo
MAKE_ARGS=	JISYO=${SKKJISYO}
PLIST_SUB=	JISYONAME=${SKKJISYO}

pre-fetch:
.if defined(SKKJISYO_SIZE_INVALID)
	@${ECHO_MSG} "Error: invalid SKKJISYO_SIZE: ${SKKJISYO_SIZE}"
	@${ECHO_MSG} "SKKJISYO_SIZE should be L, M, or S."
	@${FALSE}
.endif

.include <bsd.port.mk>
