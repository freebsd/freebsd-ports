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

CJK?=		NO
GS6?=		NO
XTT?=		YES

NO_BUILD=	YES
SHAREMODE=	644
WRKSRC=		${WRKDIR}/arphic
USE_XLIB=	YES
FONTDIR=	${PREFIX}/share/fonts/TrueType
XFONTDIR=	${X11BASE}/lib/X11/fonts/TrueType
INSTALL_ENV=	PKG_PREFIX=${PREFIX} CJK=${CJK} GS6=${GS6} XTT=${XTT} \
		XFREE86_VERSION=${XFREE86_VERSION}

.include <bsd.port.pre.mk>

.if ${CJK} != "NO"
RUN_DEPENDS+=	bg5latex:${PORTSDIR}/chinese/CJK
.endif
.if ${GS6} != "NO"
RUN_DEPENDS+=	${LOCALBASE}/share/ghostscript/CJK/CMap/B5pc-H:${PORTSDIR}/chinese/ghostscript6
.endif
.if ${XFREE86_VERSION} == 3 && ${XTT} != "NO"
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
