# New ports collection makefile for:	xcin
# Version required:	xcin-2.3.02
# Date created:		Nov 28 ,1997
# Whom:			Yen-Shuo Su <yssu@CCCA.NCTU.edu.tw>
#
# $Id: Makefile,v 1.6 1998/03/09 07:07:17 vanilla Exp $
#

DISTNAME=       xcin-2.3.02
PKGNAME=        zh-xcin-2.3.02
CATEGORIES=	chinese x11
MASTER_SITES=	http://www.freebsd.org/~vanilla/ \
		ftp://ftp.ncu.edu.tw/OS/linux/chinese/xcin/ \
		ftp://linux.cis.nctu.edu.tw/packages/chinese/xcin/

MAINTAINER=     yssu@CCCA.NCTU.edu.tw

RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/chinese/kc15f.pcf.gz:${PORTSDIR}/chinese/kcfonts

USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS	=-prefix="${X11BASE}" \
		-x-font-prefix="${X11BASE}/lib/X11/fonts"
MAN1=		xcin.1 crxvt.1 cin2tab.1

.if defined(USE_24_FONT)
CONFIGURE_ARGS+=-use-24-fonts
.else
pre-fetch:
	@echo
	@echo You can set USE_24_FONT=YES if you want to use 24 fonts
	@echo as default when xcin is running.
	@echo
.endif

.include <bsd.port.mk>
