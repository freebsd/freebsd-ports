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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Four Chinese Big5/GB TrueType fonts made by Arphic Technology

RUN_DEPENDS=	ttfm.sh:${PORTSDIR}/chinese/ttfm

NO_BUILD=	yes
SHAREMODE=	644
WRKSRC=		${WRKDIR}/arphic
USE_XLIB=	yes
FONTDIR=	${PREFIX}/share/fonts/TrueType
XFONTDIR=	${X11BASE}/lib/X11/fonts/TrueType
INSTALL_ENV=	PKG_PREFIX=${PREFIX} WANT_GS=${WANT_GS} WITHOUT_X=${WITHOUT_X}

.include <bsd.port.pre.mk>

.if defined(WANT_GS)
RUN_DEPENDS+=	${LOCALBASE}/share/ghostscript/Resource/ai0/CMap/Identity-H:${PORTSDIR}/print/adobe-cmaps
.endif

pre-fetch:
.if defined(WANT_GS)
	@${ECHO} "Ghostscript support will be added."
.endif
.if defined(WITHOUT_X)
	@${ECHO} "X Window support will NOT be added."
.endif
.if !defined(WANT_GS) && !defined(WITHOUT_X)
	@${ECHO} --
	@${ECHO} "Type \"make WANT_GS=yes\" if you want Ghostscript support."
	@${ECHO} "Type \"make WITHOUT_X=yes\" if you DONT want X Window support."
	@${ECHO} "You can use them in combinations."
	@${ECHO} --
.endif

do-install:
	@${MKDIR} ${FONTDIR}
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
