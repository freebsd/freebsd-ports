# New ports collection makefile for:	HKSCS Chinese TrueType fonts
# Date created:		29 Nov 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	mingunittf
PORTVERSION=	1.08
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	http://www.info.gov.hk/digital21/chi/hkscs/download/
DISTNAME=	ming_uni.ttf
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chinese Big5HKSCS TrueType fonts

BUILD_DEPENDS=	ttfm.sh:${PORTSDIR}/chinese/ttfm \
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	ttfm.sh:${PORTSDIR}/chinese/ttfm \
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/minguni.ttf
NO_BUILD=	yes
SHAREMODE=	644
WRKSRC=		${WRKDIR}
USE_XLIB=	yes
FONTDIR=	${PREFIX}/share/fonts/TrueType
XFONTDIR=	${X11BASE}/lib/X11/fonts/TrueType
INSTALL_ENV=	PKG_PREFIX=${PREFIX}

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${FONTDIR}
	@${INSTALL_DATA} ${WRKSRC}/minguni.ttf ${FONTDIR}
	@${ECHO_MSG} "===> Running ttfm.sh"
	-@${PREFIX}/bin/ttfm.sh --add xttfm minguni.ttf
	@${ECHO_MSG} "===> Running fc-cache"
	-@${X11BASE}/bin/fc-cache -f -v ${XFONTDIR}

.include <bsd.port.post.mk>
