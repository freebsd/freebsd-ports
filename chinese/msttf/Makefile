# New ports collection makefile for:	Microsoft Windows Chinese TrueType fonts
# Date created:		28 Feb 2004
# Whom:			LI Dong <ld@FreeBSD.org.cn>
#
# $FreeBSD$
#

PORTNAME=	msttf
PORTVERSION=	1.0
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	#
DISTFILES=	${MSTTF_SIMHEI} ${MSTTF_SIMSUN} ${MSTTF_TAHOMA}
DIST_SUBDIR=	msttf
EXTRACT_ONLY=	# none

MAINTAINER=	ld@FreeBSD.org.cn
COMMENT=	Three TrueType fonts from Microsoft Windows(TM) 2000/XP

RUN_DEPENDS=	ttfm.sh:${PORTSDIR}/chinese/ttfm

MSTTF_SIMHEI=	simhei.ttf
MSTTF_SIMSUN=	simsun.ttc
MSTTF_TAHOMA=	tahoma.ttf

IGNOREFILES=	${MSTTF_SIMHEI} ${MSTTF_SIMSUN} ${MSTTF_TAHOMA}
RESTRICTED=	"Redistribution of pre-compiled binaries is not permitted"
NO_PACKAGE=	"Redistribution of pre-compiled binaries is not permitted"

NO_BUILD=	yes
SHAREMODE=	644
NO_WRKSUBDIR=	yes
USE_XLIB=	yes
FONTDIR=	${PREFIX}/share/fonts/TrueType
XFONTDIR=	${X11BASE}/lib/X11/fonts/TrueType
INSTALL_ENV=	PKG_PREFIX=${PREFIX} XFREE86_VERSION=${XFREE86_VERSION} \
		WANT_GS=${WANT_GS} WITHOUT_X=${WITHOUT_X}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${MSTTF_SIMHEI})
IGNORE= Because of licensing restrictions, you must copy the three TrueType \
	fonts from your copy of Microsoft Windows(TM) 2000/XP manually. End \
	user can use these fonts freely in his/her own computers. Please \
	place these fonts in ${DISTDIR}/${DIST_SUBDIR}. \
	Fonts: ${MSTTF_SIMHEI} of ${MSTTF_SIMHEI} ${MSTTF_SIMSUN} ${MSTTF_TAHOMA}

.endif

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${MSTTF_SIMSUN})
IGNORE=	Because of licensing restrictions, you must copy the three \
	TrueType fonts from your copy of Microsoft Windows(TM) \
	2000/XP manually. End user can use these fonts freely in \
	his/her own computers. Please place these fonts in \
	${DISTDIR}/${DIST_SUBDIR}. \
	Fonts: ${MSTTF_SIMSUN} of ${MSTTF_SIMHEI} ${MSTTF_SIMSUN} ${MSTTF_TAHOMA}\n
.endif

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${MSTTF_TAHOMA})
IGNORE= Because of licensing restrictions, you must copy the three \
	TrueType fonts from your copy of Microsoft Windows(TM) \
	2000/XP manually. End user can use these fonts freely in \
	his/her own computers. Please place these fonts in \
	${DISTDIR}/${DIST_SUBDIR}. \
	Fonts: ${MSTTF_TAHOMA} of ${MSTTF_SIMHEI} ${MSTTF_SIMSUN} ${MSTTF_TAHOMA}\n
.endif

do-install:
	@${MKDIR} ${FONTDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${MSTTF_SIMHEI} ${FONTDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${MSTTF_SIMSUN} ${FONTDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${MSTTF_TAHOMA} ${FONTDIR}
	@${SETENV} ${INSTALL_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
