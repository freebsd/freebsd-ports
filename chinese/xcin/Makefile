# New ports collection makefile for:	xcin
# Version required:	xcin-2.3.01
# Date created:		Nov 28 ,1997
# Whom:			Yen-Shuo Su <yssu@CCCA.NCTU.edu.tw>
#
# $Id$
#

DISTNAME=       xcin-2.3.01
PKGNAME=        zh-xcin-2.3.01
CATEGORIES=	chinese x11
MASTER_SITES=   ftp://ftp.ncu.edu.tw/OS/linux/chinese/xcin/ \
		ftp://linux.cis.nctu.edu.tw/packages/chinese/xcin/

MAINTAINER=     yssu@CCCA.NCTU.edu.tw

RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/chinese/kc15.pcf.gz:${PORTSDIR}/chinese/kcfonts

USE_X11=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=-prefix="${X11BASE}" \
		-x-font-prefix="${X11BASE}/lib/X11/fonts"
MAN1=		xcin.1 cin2tab.1

.if !defined(USE_24_FONT)
pre-fetch:
	@echo
	@echo You can set USE_24_FONT=YES if you want to use 24 fonts
	@echo as default when xcin is running.
	@echo
.else
pre-configure:
CONFIGURE_ARGS+=-use-24-fonts
.endif

.include <bsd.port.mk>
