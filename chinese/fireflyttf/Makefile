# New ports collection makefile for:	firefly TrueType Font
# Date created:		2 Sep 2004
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	fireflyttf
PORTVERSION=	1.1.0
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	http://www.study-area.org/apt/firefly-font/
DISTNAME=	fireflysung.ttf
EXTRACT_SUFX=	.gz

MAINTAINER=	statue@freebsd.sinica.edu.tw
COMMENT=	Firefly TrueType Font is combine of two arphic sung fonts

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig \
		ttfm.sh:${PORTSDIR}/chinese/ttfm
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig \
		ttfm.sh:${PORTSDIR}/chinese/ttfm

NO_BUILD=	yes
WRKSRC=		${WRKDIR}
USE_XLIB=	yes
FONTDIR=	${PREFIX}/share/fonts/TrueType
XFONTDIR=	${X11BASE}/lib/X11/fonts/TrueType
EXTRACT_AFTER_ARGS=	> ${DISTNAME}

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${FONTDIR}
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${FONTDIR}
	@${ECHO_MSG} "===> Running ttfm.sh"
	-@${PREFIX}/bin/ttfm.sh --add xttfm ${DISTNAME}
	@${ECHO_MSG} "===> Running fc-cache"
	-@${X11BASE}/bin/fc-cache -f -v ${XFONTDIR}
	${INSTALL_DATA} ${FILESDIR}/local.conf-sung ${FONTDIR}
	${INSTALL_DATA} ${FILESDIR}/local.conf-sung ${X11BASE}/etc/fonts/local.conf

.include <bsd.port.post.mk>
