# New ports collection makefile for:	firefly TrueType Font
# Date created:		2 Sep 2004
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	fireflyttf
PORTVERSION=	1.2.6
PORTREVISION=	0
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	http://www.study-area.org/apt/firefly-font/
DISTNAME=	fireflysung.ttf
EXTRACT_SUFX=	.gz

MAINTAINER=	statue@freebsd.sinica.edu.tw
COMMENT=	Firefly TrueType Font is combine of two arphic sung fonts

NO_BUILD=	yes
WRKSRC=		${WRKDIR}
EXTRACT_AFTER_ARGS=	> ${DISTNAME}

TTF=		${DISTNAME}

.if !defined(WITHOUT_X11)
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

do-install:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/${TTF} ${FONTSDIR}
	${INSTALL_DATA} ${FILESDIR}/local.conf-sung ${FONTSDIR}
.if !defined(WITHOUT_X11)
	${INSTALL_DATA} ${FILESDIR}/local.conf-sung ${X11BASE}/etc/fonts/local.conf
.endif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>
