# New ports collection makefile for:	skk
# Date created:		04 Mar 1997
# Whom:			Makoto Matsushita <matusita@jp.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	skk
PORTVERSION=	9.6
CATEGORIES=	japanese elisp
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	matusita@FreeBSD.org

SKKJISYO_SIZE?=	L
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}
PORT_SKK_JISYO=	${.CURDIR}/../../japanese/skk-jisyo
PORT_SKK_TOOLS=	${.CURDIR}/../../japanese/skk-tools
PORT_SKK_ELISP=	${.CURDIR}/../../japanese/skk-elisp
PORT_SKK_SERV=	${.CURDIR}/../../japanese/skkserv

RUN_DEPENDS=	${PREFIX}/share/skk/${SKKJISYO}:${PORT_SKK_JISYO} \
		${PREFIX}/bin/skkdic-count:${PORT_SKK_TOOLS} \
		${PREFIX}/share/mule/site-lisp/skk/skk.el:${PORT_SKK_ELISP} \
		${PREFIX}/sbin/skkserv:${PORT_SKK_SERV}

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
