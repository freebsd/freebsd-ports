# New ports collection makefile for:	zh-wangttf
# Date created:		2006/12/01
# Whom:			chinsan <chinsan.tw@gmail.com>
# Origin:		Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#			2004/09/01
#
# $FreeBSD$
#

PORTNAME=	wangttf
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	http://cle.linux.org.tw/fonts/wangfonts/:main \
		http://cle.linux.org.tw/fonts/truetype/:another \
		ftp://cle.linux.org.tw/pub2/fonts/wangfonts/:main \
		ftp://cle.linux.org.tw/pub2/fonts/truetype/:another
DISTFILES=	wp010-05.ttf:main wp010-08.ttf:main wp110-05.ttf:main \
		wp110-08.ttf:main wp210-05.ttf:main wp210-08.ttf:main \
		wp310-05.ttf:main wp310-08.ttf:main wts11.ttf:main \
		wts43.ttf:main wts47.ttf:main wts55.ttf:main \
		wcl-01.ttf:another wcl-02.ttf:another wcl-03.ttf:another \
		wcl-04.ttf:another wcl-05.ttf:another wcl-06.ttf:another \
		wcl-07.ttf:another wcl-08.ttf:another wcl-09.ttf:another \
		wcl-10.ttf:another
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Many Chinese Big5 TrueType fonts, made by Dr. Hann-Tzong Wang

NO_PACKAGE=	Package will be 216MB, set FORCE_PACKAGE if you really want to build it

DIST_SUBDIR=	zh-wangttf
NO_BUILD=	yes

TTF=		${DISTFILES:C/:[^:]+$//}
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
