# New ports collection makefile for:	skk-jisyo
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	skk-jisyo
PORTVERSION=	9.6
PKGNAMESUFFIX=	${SKKJISYO_SIZE}
CATEGORIES=	japanese
MASTER_SITES=	ftp://skk.kuis.kyoto-u.ac.jp/skk/${PORTVERSION}/
DISTNAME=	skk${PORTVERSION}

MAINTAINER=	matusita@jp.FreeBSD.org

.if !defined(SKKJISYO_SIZE)
SKKJISYO_SIZE=	L
.else
.if ${SKKJISYO_SIZE} != L && ${SKKJISYO_SIZE} != M && ${SKKJISYO_SIZE} != S
SKKJISYO_SIZE_INVALID=	yes
.endif
.endif
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}

WRKSRC=		${WRKDIR}/skk-${PORTVERSION}
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
