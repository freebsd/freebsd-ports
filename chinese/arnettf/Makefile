# New ports collection makefile for:	arne TrueType Font
# Date created:		10 Dec 2004
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	arnettf
PORTVERSION=	0.0.20041031
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	http://debian.linux.org.tw/pub/3Anoppix/people/arne/uming/ \
		http://debian.linux.org.tw/pub/3Anoppix/people/arne/ukai/
DISTFILES=	ttf-arphic-uming_0.0.20041031-1.tar.gz \
		ttf-arphic-ukai_0.0.20041031-1.tar.gz

MAINTAINER=	ports@FreeBSD.Org
COMMENT=	Arne TrueType Font is combine of arphic ming and kai fonts

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig \
		ttfm.sh:${PORTSDIR}/chinese/ttfm
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig \
		ttfm.sh:${PORTSDIR}/chinese/ttfm

NO_BUILD=	yes
WRKSRC=		${WRKDIR}
USE_XLIB=	yes
FONTDIR=	${PREFIX}/share/fonts/TrueType
XFONTDIR=	${X11BASE}/lib/X11/fonts/TrueType

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${FONTDIR}
	@${INSTALL_DATA} ${WRKSRC}/ttf-arphic-ukai-0.0.20041031/ukai.ttf ${FONTDIR}
	@${INSTALL_DATA} ${WRKSRC}/ttf-arphic-uming-0.0.20041031/uming.ttf ${FONTDIR}
	@${ECHO_MSG} "===> Running ttfm.sh"
	-@${PREFIX}/bin/ttfm.sh --add xttfm ukai.ttf
	-@${PREFIX}/bin/ttfm.sh --add xttfm uming.ttf
	@${ECHO_MSG} "===> Running fc-cache"
	-@${X11BASE}/bin/fc-cache -f -v ${XFONTDIR}

.include <bsd.port.post.mk>
