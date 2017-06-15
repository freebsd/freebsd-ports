# Created by: Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	opendesktop-fonts
PORTVERSION=	1.4.2
PORTREVISION=	5
CATEGORIES=	chinese x11-fonts
MASTER_SITES?=	ftp://ftp.opendesktop.org.tw/odp/ODOFonts/OpenFonts/ \
		LOCAL/chinsan/fonts

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ming and Kai face of OpenDesktop fonts

CONFLICTS=	zh-fireflyttf-[0-9]*
DIST_SUBDIR=	OpenFonts
NO_BUILD=	yes
NO_ARCH=	yes

TTF=		odokai-ExtB.ttf odokai.ttf odosung-ExtB.ttf odosung.ttc
PLIST_FILES=	${FONTSDIR_REL}/local.conf-odo

.include "${.CURDIR}/../ttfm/Makefile.ttf"

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100077
# chmod -R bug
post-extract:
	@${CHMOD} 0755 ${WRKSRC}/license
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr,${LOCALBASE},; s,opendesktop,,g' \
		${WRKSRC}/FAPIcidfmap.zh_CN ${WRKSRC}/FAPIcidfmap.zh_TW \
		${WRKSRC}/cidfmap.zh_CN ${WRKSRC}/cidfmap.zh_TW
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
.for i in ${TTF}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${FONTSDIR}
.endfor
	${INSTALL_DATA} ${FILESDIR}/local.conf-odo ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
