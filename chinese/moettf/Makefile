# New ports collection makefile for:	Chinese Big5 TrueType fonts
# Date created:		9 July 1999
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	moettf
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	http://www.edu.tw/download/mandr/biauword/5879/ \
		http://www.edu.tw/download/mandr/allbook/lishu/ \
		http://www.edu.tw/download/mandr/biauword/kai/ \
		ftp://freebsd.sinica.edu.tw/pub/keith/moettf/ \
		ftp://ftp.cc.ntut.edu.tw/OS/Linux/packages/chinese/fonts/twmoefont/ttf/
DISTFILES=	moe_kai.ttf moe_sung.ttf edustds1.exe edustds2.exe \
		edustd-15.exe kai-pc.ttf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Three Chinese BIG5 TrueType fonts: Kai LiShu Sung SungExt

EXTRACT_DEPENDS=unrar:${PORTSDIR}/archivers/unrar
RUN_DEPENDS=	ttfm.sh:${PORTSDIR}/chinese/ttfm

USE_XLIB=	yes
DIST_SUBDIR=	zh-moettf

NO_CDROM=	"Contact Taiwan's Ministry of Education for commercial use."
NO_BUILD=	yes
SHAREMODE=	644
FONTDIR=	${PREFIX}/share/fonts/TrueType
XFONTDIR=	${X11BASE}/lib/X11/fonts/TrueType

OPTIONS=	CJK "CJK support" off \
		GS "Ghostscript support" off \
		X "X Window support" on \
		DEFAULT "set MOETTF the default font" off

.include <bsd.port.pre.mk>

INSTALL_ENV=	PKG_PREFIX=${PREFIX} \
		DEFAULT=${WITH_DEFAULT} WANT_CJK=${WITH_CJK} \
		WANT_GS=${WITH_GS} WITHOUT_X=${WITHOUT_X}

.if defined(WITH_CJK)
RUN_DEPENDS+=	bg5latex:${PORTSDIR}/chinese/CJK
.endif
.if defined(WITH_GS)
RUN_DEPENDS+=	${LOCALBASE}/share/ghostscript/Resource/ai0/CMap/Identity-H:${PORTSDIR}/print/adobe-cmaps
.endif

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@unrar x ${DISTDIR}/${DIST_SUBDIR}/edustd-15.exe ${WRKDIR}
	@${MV} ${WRKDIR}/Edustd-15.TTF ${WRKDIR}/moe_lishu.ttf
	@unrar x ${DISTDIR}/${DIST_SUBDIR}/edustds1.exe ${WRKDIR}
	@${MV} ${WRKDIR}/edustds1.ttf ${WRKDIR}/moe_sungext.ttf
	@unrar x ${DISTDIR}/${DIST_SUBDIR}/edustds2.exe ${WRKDIR}
	@${MV} ${WRKDIR}/edustds2.ttf ${WRKDIR}/moe_sungsym.ttf

do-install:
.if !exists(${FONTDIR})
	@${MKDIR} ${FONTDIR}
.endif
	@${INSTALL_DATA} ${WRKDIR}/moe_lishu.ttf ${FONTDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/moe_kai.ttf ${FONTDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/kai-pc.ttf ${FONTDIR}/moe_kai_pc.ttf
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/moe_sung.ttf ${FONTDIR}
	@${INSTALL_DATA} ${WRKDIR}/moe_sungext.ttf ${FONTDIR}
	@${INSTALL_DATA} ${WRKDIR}/moe_sungsym.ttf ${FONTDIR}
	@${SETENV} ${INSTALL_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
