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

NO_BUILD=	yes
SHAREMODE=	644
WRKSRC=		${WRKDIR}/arphic
USE_XLIB=	yes
FONTDIR=	${PREFIX}/share/fonts/TrueType
XFONTDIR=	${X11BASE}/lib/X11/fonts/TrueType
INSTALL_ENV=	PKG_PREFIX=${PREFIX} XFREE86_VERSION=${XFREE86_VERSION} \
		WANT_CJK=${WANT_CJK} WANT_GS=${WANT_GS} \
		WITHOUT_X=${WITHOUT_X}

.include <bsd.port.pre.mk>

.if defined(WANT_CJK)
RUN_DEPENDS+=	bg5latex:${PORTSDIR}/chinese/CJK
.endif
.if defined(WANT_GS)
RUN_DEPENDS+=	${LOCALBASE}/share/ghostscript/Resource/ai0/CMap/Identity-H:${PORTSDIR}/print/adobe-cmaps
.endif
.if ${XFREE86_VERSION} == 3 && !defined(WITHOUT_X)
RUN_DEPENDS+=	mkfontdir.pl:${PORTSDIR}/x11-servers/XttXF86srv-common
.endif

pre-fetch:
.if defined(WANT_CJK)
	@${ECHO} "CJK support will be added."
.endif
.if defined(WANT_GS)
	@${ECHO} "Ghostscript support will be added."
.endif
.if defined(WITHOUT_X)
	@${ECHO} "X Window support will NOT be added."
.endif
.if !defined(WANT_CJK) && !defined(WANT_GS) && !defined(WITHOUT_X)
	@${ECHO} --
	@${ECHO} "Type \"make WANT_CJK=yes\" if you want CJK support."
	@${ECHO} "Type \"make WANT_GS=yes\" if you want Ghostscript support."
	@${ECHO} "Type \"make WITHOUT_X=yes\" if you DONT want X Window support."
	@${ECHO} "You can use them in combinations."
	@${ECHO} --
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
