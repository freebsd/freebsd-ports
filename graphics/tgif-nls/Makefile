# New ports collection makefile for:    tgif-nls
# Version required:     4.1.8
# Date created:         3 May 1999
# Whom:                 one@netlab.is.tsukuba.ac.jp
#
# $Id: Makefile,v 1.1.1.1 1999/05/03 04:24:16 steve Exp $
#

DISTNAME=	tgif-4.1.8
PKGNAME=	tgif-nls-4.1.8
CATEGORIES=	graphics
MASTER_SITES=	ftp://bourbon.cs.umd.edu/pub/tgif/ \
		ftp://ftp.cs.ucla.edu/pub/tgif/

MAINTAINER=	one@netlab.is.tsukuba.ac.jp

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm \
		pnmtotiff:${PORTSDIR}/graphics/netpbm \
		ppmtoxpm:${PORTSDIR}/graphics/netpbm \
		ppmtogif:${PORTSDIR}/graphics/netpbm \
		xbmtopbm:${PORTSDIR}/graphics/netpbm \
		xpmtoppm:${PORTSDIR}/graphics/netpbm

USE_IMAKE=	yes
MAN1=		tgif.1

post-extract:
		@cd ${WRKSRC}; ${RM} -f Tgif.tmpl; \
		${SED} -e 's#/usr/share/locale#${PREFIX}/share/locale#' \
			Tgif.tmpl-freebsd > Tgif.tmpl; \
		${ECHO} "EXTRA_INCLUDES += -I${LOCALBASE}/include" \
			>> Tgif.tmpl; \
		${ECHO} "EXTRA_LIBRARIES += -L${LOCALBASE}/lib -lintl" \
			>> Tgif.tmpl; \
		${MV} po/Po.tmpl po/Po.tmpl.orig; \
		${SED} -e 's#/usr/share/locale#${PREFIX}/share/locale#' \
			po/Po.tmpl.orig > po/Po.tmpl; \

post-patch:
		@cd ${WRKSRC}; \
		${MV} tgif.Xdefaults tgif.Xdefaults.org; \
		${SED} -e 's#/usr/local#${PREFIX}#' \
			-e 's#/usr/share/lib#${PREFIX}/share/locale#' \
			tgif.Xdefaults.org > tgif.Xdefaults

post-install:
		${MKDIR} ${PREFIX}/lib/X11/ja_JP.EUC/app-defaults
		${INSTALL_DATA} ${FILESDIR}/tgif.Xdefaults.ja \
			${PREFIX}/lib/X11/ja_JP.EUC/app-defaults/Tgif

.include <bsd.port.mk>
