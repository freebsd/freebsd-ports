# New ports collection makefile for:	Arphic Chinese TrueType fonts
# Date created:		13 Oct 1999
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	arphicttf
PORTVERSION=	2.11
PORTREVISION=	1
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	keith@FreeBSD.org

RUN_DEPENDS=	ttfm.sh:${PORTSDIR}/chinese/ttfm

WANT_CJK?=	NO
WANT_GS6?=	NO
WANT_X?=	YES

NO_BUILD=	yes
SHAREMODE=	644
WRKSRC=		${WRKDIR}/arphic
USE_XLIB=	yes
FONTDIR=	${PREFIX}/share/fonts/TrueType
XFONTDIR=	${X11BASE}/lib/X11/fonts/TrueType
INSTALL_ENV=	PKG_PREFIX=${PREFIX} XFREE86_VERSION=${XFREE86_VERSION} \
		WANT_CJK=${WANT_CJK} WANT_GS6=${WANT_GS6} WANT_X=${WANT_X}

.include <bsd.port.pre.mk>

.if ${WANT_CJK} != "NO"
RUN_DEPENDS+=	bg5latex:${PORTSDIR}/chinese/CJK
.endif
.if ${WANT_GS6} != "NO"
RUN_DEPENDS+=	${LOCALBASE}/share/ghostscript/CJK/CMap/B5pc-H:${PORTSDIR}/chinese/ghostscript6
.endif
.if ${XFREE86_VERSION} == 3 && ${WANT_X} != "NO"
RUN_DEPENDS+=	mkfontdir.pl:${PORTSDIR}/x11-servers/XttXF86srv-common
.endif

do-install:
.if !exists(${FONTDIR})
	@${MKDIR} ${FONTDIR}
.endif
	@${INSTALL_DATA} ${WRKSRC}/font/bkai00mp.ttf ${FONTDIR}
	@${INSTALL_DATA} ${WRKSRC}/font/bsmi00lp.ttf ${FONTDIR}
	@${INSTALL_DATA} ${WRKSRC}/font/gbsn00lp.ttf ${FONTDIR}
	@${INSTALL_DATA} ${WRKSRC}/font/gkai00mp.ttf ${FONTDIR}
	@${RM} -fr ${FONTDIR}/arphic
	@${MKDIR} ${FONTDIR}/arphic
	@${CP} -fr ${WRKSRC}/license ${FONTDIR}/arphic
	@${CP} -f ${WRKSRC}/logo.gif ${WRKSRC}/release.txt ${FONTDIR}/arphic
	@${SETENV} ${INSTALL_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
