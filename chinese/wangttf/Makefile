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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Many Chinese Big5 TrueType fonts, made by Dr. Hann-Tzong Wang

DIST_SUBDIR=	zh-wangttf
NO_BUILD=	yes

TTF=		${DISTFILES}
PORTDOCS=	wangttf.txt

do-install:
	@${MKDIR} ${FONTSDIR}
.for i in ${TTF}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${i} ${FONTSDIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>
