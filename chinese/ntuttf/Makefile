# New ports collection makefile for:	NTU Chinese TrueType fonts
# Date created:		11 April 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	ntuttf
PORTVERSION=	1.0
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://cle.linux.org.tw/pub/fonts/ttf/unicode/ntu/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/ntuttf/
DISTFILES=	NTU_FS_M.TTF NTU_KAI.TTF NTU_LI_M.TTF NTU_MB.TTF \
		NTU_MM.TTF NTU_MR.TTF NTU_TW.TTF
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Seven Chinese Big5 TrueType fonts made by NTU

RUN_DEPENDS=	ttfm.sh:${PORTSDIR}/chinese/ttfm

NO_BUILD=	yes
SHAREMODE=	644
USE_XLIB=	yes
FONTDIR=	${PREFIX}/share/fonts/TrueType
XFONTDIR=	${X11BASE}/lib/X11/fonts/TrueType
INSTALL_ENV=	PKG_PREFIX=${PREFIX} \
		WANT_CJK=${WANT_CJK} WANT_GS=${WANT_GS} \
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
.if !exists(${FONTDIR})
	@${MKDIR} ${FONTDIR}
.endif
.for i in ${DISTFILES}
	@${INSTALL_DATA} ${DISTDIR}/${i} ${FONTDIR}
.endfor
	@${SETENV} ${INSTALL_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
