# New ports collection makefile for:	OpenDesktop.Org.tw Font
# Date created:		2 Sep 2004
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	opendesktop-fonts
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	chinese x11-fonts
MASTER_SITES?=	ftp://ftp.opendesktop.org.tw/odp/ODOFonts/OpenFonts/ \
		LOCAL/chinsan/fonts

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ming and Kai face of OpenDesktop fonts

CONFLICTS=	zh-fireflyttf-*
DIST_SUBDIR=	OpenFonts
NO_BUILD=	yes

TTF=		odokai-ExtB.ttf odokai.ttf odosung-ExtB.ttf odosung.ttc

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X11)
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

post-extract:
	@${CHMOD} 0755 ${WRKSRC}/license

post-patch:
	@${REINPLACE_CMD} -e 's,/usr,${LOCALBASE},; s,opendesktop,,g' \
		${WRKSRC}/FAPIcidfmap.zh_CN ${WRKSRC}/FAPIcidfmap.zh_TW \
		${WRKSRC}/cidfmap.zh_CN ${WRKSRC}/cidfmap.zh_TW
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-install:
	${MKDIR} ${FONTSDIR}
.for i in ${TTF}
	${INSTALL_DATA} ${WRKSRC}/${i} ${FONTSDIR}
.endfor
	${INSTALL_DATA} ${FILESDIR}/local.conf-odo ${FONTSDIR}
.if !defined(WITHOUT_X11)
	${INSTALL_DATA} ${FILESDIR}/local.conf-odo ${LOCALBASE}/etc/fonts/local.conf
.endif

.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>
