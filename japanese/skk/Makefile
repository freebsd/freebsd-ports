# New ports collection makefile for:	skk
# Version required:	9.6
# Date created:		04 Mar 1997
# Whom:			Makoto Matsushita <matusita@jp.freebsd.org>
#
# $Id: Makefile,v 1.10 1998/11/15 12:21:55 kuriyama Exp $
#

DISTNAME=	skk9.6
PKGNAME=	ja-skk-9.6
CATEGORIES=	japanese elisp
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	matusita@jp.freebsd.org

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
