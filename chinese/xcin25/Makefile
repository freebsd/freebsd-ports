# New ports collection makefile for:	xcin
# Version required:	xcin-2.3.03
# Date created:		Nov 28 ,1997
# Whom:			Yen-Shuo Su <yssu@CCCA.NCTU.edu.tw>
#
# $Id: Makefile,v 1.8 1998/11/23 12:44:04 vanilla Exp $
#

DISTNAME=	xcin-2.3.03
PKGNAME=	zh-xcin-2.3.03
CATEGORIES=	chinese
MASTER_SITES=	ftp://xcin.linux.org.tw/pub/xcin/xcin/ \
		ftp://ftp.ncu.edu.tw/OS/Linux/Chinese/xcin/xcin/ \
		ftp://linux.cis.nctu.edu.tw/packages/chinese/X/xcin/xcin/

MAINTAINER=	yssu@CCCA.NCTU.edu.tw

RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/local/kc15f.pcf.gz:${PORTSDIR}/chinese/kcfonts

USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${X11BASE}" --os=FreeBSD --no-menu

MAN1=		xcin.1 cin2tab.1

.include <bsd.port.mk>
