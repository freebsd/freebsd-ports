# New ports collection makefile for:	Arphic Chinese TrueType fonts
# Date created:		13 Oct 1999
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	arphicttf
PORTVERSION=	2.11
PORTREVISION=	1
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Four Chinese Big5/GB TrueType fonts made by Arphic Technology

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/arphic

TTF=		bkai00mp.ttf bsmi00lp.ttf gbsn00lp.ttf gkai00mp.ttf

do-install:
	@${MKDIR} ${FONTSDIR}
.for ttf in ${TTF}
	${INSTALL_DATA} ${WRKSRC}/font/${ttf} ${FONTSDIR}
.endfor
	@${MKDIR} ${DATADIR}
	${CP} -fr ${WRKSRC}/license ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/logo.gif ${WRKSRC}/release.txt ${DATADIR}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>
