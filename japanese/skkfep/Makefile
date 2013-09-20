# Created by: Yusuke Nawano <azuki@azkey.org>
# $FreeBSD$

PORTNAME=	skkfep
PORTVERSION=	0.87
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	http://homepage2.nifty.com/aito/skkfep/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SKK-like Kana-to-Kanji FrontEnd Processor

RUN_DEPENDS=	${LOCALBASE}/sbin/skkserv:${PORTSDIR}/japanese/skk

MAN1=		skkfep.1
PLIST_FILES=	bin/skkfep

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skkfep ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/skkfep.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
