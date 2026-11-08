PORTNAME=	skk
PORTVERSION=	9.6
PORTREVISION=	4
CATEGORIES=	japanese elisp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The "meta-port" for the SKK Japanese-input software
WWW=		http://openlab.jp/skk/

DEPRECATED=	The role is over, many new SKK implementations do not require a dictionary server
EXPIRATION_DATE=2026-12-15

RUN_DEPENDS=	${LOCALBASE}/share/skk/${SKKJISYO}:japanese/skk-jisyo \
		${LOCALBASE}/bin/skkdic-count:japanese/skk-tools \
		${LOCALBASE}/sbin/skkserv:japanese/skkserv

USES=		metaport

SKKJISYO_SIZE?=	L
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}

.include <bsd.port.mk>
