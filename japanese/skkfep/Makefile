# New ports collection Makefile for:	skkfep
# Date created:		22 Jul 1998
# Whom:			Yusuke Nawano <azuki@azkey.org>
#
# $FreeBSD$
#

PORTNAME=	skkfep
PORTVERSION=	0.86c
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/s/skkfep
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SKK-like Kana-to-Kanji FrontEnd Processor

RUN_DEPENDS=	${LOCALBASE}/sbin/skkserv:${PORTSDIR}/japanese/skk

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		skkfep.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skkfep ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/skkfep.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
