# New ports collection makefile for:	xcin
# Date created:		Nov 28 ,1997
# Whom:			Yen-Shuo Su <yssu@CCCA.NCTU.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	xcin
PORTVERSION=	2.3.04.3
CATEGORIES=	chinese
MASTER_SITES=	ftp://xcin.linux.org.tw/pub/xcin/xcin/old/ \
		ftp://ftp.ncu.edu.tw/OS/Linux/Chinese/xcin/xcin/ \
		ftp://linux.cis.nctu.edu.tw/packages/chinese/X/xcin/xcin/
DISTNAME=	xcin-2.3.04-3

MAINTAINER=	yssu@CCCA.NCTU.edu.tw

RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/local/kc15f.pcf.gz:${PORTSDIR}/chinese/kcfonts

NO_LATEST_LINK=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${X11BASE}" --os=FreeBSD --no-menu

MAN1=		xcin.1 cin2tab.1

.include <bsd.port.mk>
