# New ports collection makefile for:    tgif-nls
# Version required:     4.1.16
# Date created:         3 May 1999
# Whom:                 one@netlab.is.tsukuba.ac.jp
#
# $FreeBSD$
#

DISTNAME=	tgif-4.1.16
PKGNAME=	tgif-nls-4.1.16
CATEGORIES=	graphics
MASTER_SITES=	ftp://bourbon.cs.umd.edu/pub/tgif/ \
		ftp://ftp.cs.ucla.edu/pub/tgif/

MAINTAINER=	one@netlab.is.tsukuba.ac.jp

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm

USE_IMAKE=	yes
XMKMF=		LOCALBASE=${LOCALBASE} xmkmf -a

MAN1=		tgif.1

pre-patch:
		@cd ${WRKSRC}; ${RM} -f Tgif.tmpl; \
		${CP} Tgif.tmpl-freebsd Tgif.tmpl

post-patch:
		@cd ${WRKSRC}; \
		${MV} tgif.Xdefaults tgif.Xdefaults.org; \
		${SED} -e "s#/usr/local#${PREFIX}#" \
			-e "s#/usr/share/lib#${PREFIX}/share/locale#" \
			tgif.Xdefaults.org > tgif.Xdefaults

post-install:
		${MKDIR} ${PREFIX}/lib/X11/ja_JP.EUC/app-defaults
		${INSTALL_DATA} ${FILESDIR}/tgif.Xdefaults.ja \
			${PREFIX}/lib/X11/ja_JP.EUC/app-defaults/Tgif

.include <bsd.port.mk>
