# Created by: Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
# $FreeBSD$

PORTNAME=	skkserv
PORTVERSION=	9.6
PORTREVISION=	6
CATEGORIES=	japanese
MASTER_SITES=	PORTS_JP
DISTNAME=	skk${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Dictionary server for the SKK Japanese-input software

RUN_DEPENDS=	${LOCALBASE}/share/skk/${SKKJISYO}:japanese/skk-jisyo

USE_RC_SUBR=	skkserv
WRKSRC=		${WRKDIR}/skk-${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-jisyo=${SKKJISYO} \
		--libexecdir=${PREFIX}/sbin
MAKE_ARGS=	SUBDIRS='skkserv'
PLIST_FILES=	sbin/skkserv
USERS=		skkserv
GROUPS=		skkserv

SKKJISYO_SIZE?=	L
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skkserv/skkserv ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
