# New ports collection makefile for:	zh-wangttf
# Date created:		1 Sep 2004
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	wangttf
PORTVERSION=	1.3
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://cle.linux.org.tw/pub/fonts/wangfonts/ \
		ftp://cle.linux.org.tw/pub/fonts/wangfonts/WCL/
DISTFILES=	wp010-05.ttf wp010-08.ttf wp110-05.ttf wp110-08.ttf \
		wp210-05.ttf wp210-08.ttf wp310-05.ttf wp310-08.ttf \
		wt001.ttf wt002.ttf wt003.ttf wt004.ttf wt005.ttf \
		wt006.ttf wt009.ttf wt011.ttf wt014.ttf wt021.ttf \
		wt024.ttf wt028.ttf wt034.ttf wt040.ttf wt064.ttf \
		wt071.ttf wtcc02.ttf wtcc15.ttf wtg-06cut1x.ttf \
		wthc06.ttf wts11.ttf wts43.ttf wts47.ttf wts55.ttf \
		WCL-01.ttf WCL-02.ttf WCL-03.ttf WCL-04.ttf WCL-05.ttf \
		WCL-06.ttf WCL-07.ttf WCL-08.ttf WCL-09.ttf WCL-10.ttf
EXTRACT_ONLY=

MAINTAINER=	statue@freebsd.netlab.cse.yzu.edu.tw
COMMENT=	Many Chinese Big5 TrueType fonts, made by Dr. Hann-Tzong Wang

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig \
		ttfm.sh:${PORTSDIR}/chinese/ttfm
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig \
		ttfm.sh:${PORTSDIR}/chinese/ttfm

DIST_SUBDIR=	zh-wangttf
USE_BZIP2=	yes
USE_XLIB=	yes
NO_BUILD=	yes
SHAREMODE=	644
FONTDIR=	${PREFIX}/share/fonts/TrueType
XFONTDIR=	${X11BASE}/lib/X11/fonts/TrueType

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${FONTDIR}
	@${ECHO_MSG} "===> Running ttfm.sh"
.for i in ${DISTFILES}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${i} ${FONTDIR}
	-@${LOCALBASE}/bin/ttfm.sh --add xttfm ${i}
.endfor
	@${ECHO_MSG} "===> Running fc-cache"
	-@${X11BASE}/bin/fc-cache -f -v ${XFONTDIR}
	@${INSTALL_DATA} ${FILESDIR}/wangttf.txt ${FONTDIR}

.include <bsd.port.post.mk>
