# Created by: Jing-Tang Keith Jang <keith@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arphicttf
PORTVERSION=	2.11
PORTREVISION=	6
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	LOCAL/rafan/chinese/
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Four Chinese Big5/GB TrueType fonts made by Arphic Technology

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/arphic

TTF=		bkai00mp.ttf bsmi00lp.ttf gbsn00lp.ttf gkai00mp.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
.for ttf in ${TTF}
	${INSTALL_DATA} ${WRKSRC}/font/${ttf} ${STAGEDIR}${FONTSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -fr ${WRKSRC}/license ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/logo.gif ${WRKSRC}/release.txt ${STAGEDIR}${DATADIR}

.include "${.CURDIR}/../ttfm/Makefile.ttf"
.include <bsd.port.mk>
