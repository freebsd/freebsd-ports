# Created by: Makoto Matsushita <matusita@jp.freebsd.org>
# $FreeBSD$

PORTNAME=	skk
PORTVERSION=	9.6
PORTREVISION=	3
CATEGORIES=	japanese elisp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The "meta-port" for the SKK Japanese-input software

RUN_DEPENDS=	${LOCALBASE}/share/skk/${SKKJISYO}:${PORTSDIR}/japanese/skk-jisyo \
		${LOCALBASE}/bin/skkdic-count:${PORTSDIR}/japanese/skk-tools \
		${LOCALBASE}/sbin/skkserv:${PORTSDIR}/japanese/skkserv

USES=		metaport

SKKJISYO_SIZE?=	L
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}

.include <bsd.port.mk>
