# New ports collection makefile for:	zh-wangttf
# Date created:		19 Nov 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wangttf
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/statue/wangttf/
DISTFILES=	wcl-01.ttf.bz2 wcl-02.ttf.bz2 wcl-03.ttf.bz2 wcl-04.ttf.bz2 \
		wcl-05.ttf.bz2 wcl-06.ttf.bz2 wcl-07.ttf.bz2 wcl-08.ttf.bz2 \
		wcl-09.ttf.bz2 wcl-10.ttf.bz2
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ten Chinese Big5 TrueType fonts, made by Dr. Hann-Tzong Wang

RUN_DEPENDS=	ttfm.sh:${PORTSDIR}/chinese/ttfm

DIST_SUBDIR=	zh-wangttf
USE_BZIP2=	yes
USE_XLIB=	yes
NO_BUILD=	yes
SHAREMODE=	644
FONTDIR=	${PREFIX}/share/fonts/TrueType
XFONTDIR=	${X11BASE}/lib/X11/fonts/TrueType
INSTALL_ENV=	PKG_PREFIX=${PREFIX} \
		DEFAULT=${DEFAULT} WANT_CJK=${WANT_CJK} WANT_GS=${WANT_GS} \
		WITHOUT_X=${WITHOUT_X}

.include <bsd.port.pre.mk>

.if defined(WANT_CJK)
RUN_DEPENDS+=	bg5latex:${PORTSDIR}/chinese/CJK
.endif
.if defined(WANT_GS)
RUN_DEPENDS+=	${LOCALBASE}/share/ghostscript/Resource/ai0/CMap/Identity-H:${PORTSDIR}/print/adobe-cmaps
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
	@${MKDIR} ${FONTDIR}
.for i in ${DISTFILES}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${i} ${FONTDIR}
	@${EXTRACT_CMD} -dv ${FONTDIR}/${i}
.endfor
	@${INSTALL_DATA} ${FILESDIR}/wangttf.txt ${FONTDIR}
	@${SETENV} ${INSTALL_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
