# New ports collection makefile for:	skk
# Date created:		04 Mar 1997
# Whom:			Makoto Matsushita <matusita@jp.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	skk
PORTVERSION=	9.6
PORTREVISION=	1
CATEGORIES=	japanese elisp
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	matusita@FreeBSD.org
COMMENT=The "meta-port" for the SKK Japanese-input software

RUN_DEPENDS=	${LOCALBASE}/share/skk/${SKKJISYO}:${PORT_SKK_JISYO} \
		${LOCALBASE}/bin/skkdic-count:${PORT_SKK_TOOLS} \
		${LOCALBASE}/sbin/skkserv:${PORT_SKK_SERV}

NO_BUILD=	yes

SKKJISYO_SIZE?=	L
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}
PORT_SKK_JISYO=	${.CURDIR}/../../japanese/skk-jisyo
PORT_SKK_TOOLS=	${.CURDIR}/../../japanese/skk-tools
PORT_SKK_SERV=	${.CURDIR}/../../japanese/skkserv

do-install:	# empty

.include <bsd.port.mk>
