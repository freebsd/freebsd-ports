# New ports collection makefile for:	IPA TrueType fonts
# Date created:		18 July 2004
# Whom:			NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ipa-ttfonts
PORTVERSION=	20040718
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://www.grass-japan.org/FOSS4G/ipafonts/
DISTNAME=	grass5.0.3_i686-pc-linux-i18n-ipafull-gnu_bin
DIST_SUBDIR=    ipa-fonts

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Freely available Japanese TrueType fonts by Infomation-technology Promotion Agency (IPA)

USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_PACKAGE=	"License prohibits to distribute without i18n'ed GRASS http://www.grass-japan.org/FOSS4G/"
NO_CDROM=	"License prohibits to distribute without i18n'ed GRASS http://www.grass-japan.org/FOSS4G/"

FONTSDIR=	lib/X11/fonts/TrueType
LOCALFONTSDIR=	share/fonts/TrueType
MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR} \
		LOCALFONTSDIR=${LOCALBASE}/${LOCALFONTSDIR}

WRKSRC=		${WRKDIR}

DOC_FILES=	license-ipafonts.eucjp

do-install:
.if !exists(${PREFIX}/${FONTSDIR})
	@${ECHO} "*********************************************************"
	@${ECHO} "Please add ${PREFIX}/${FONTSDIR} to your font path"
	@${ECHO} "and load 'xtt' module in /etc/XF86Config."
	@${ECHO} "*********************************************************"
	${MKDIR} ${PREFIX}/${FONTSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/fonts/ipag.ttf \
			${WRKSRC}/fonts/ipagp.ttf \
			${WRKSRC}/fonts/ipagui.ttf \
			${WRKSRC}/fonts/ipam.ttf \
			${WRKSRC}/fonts/ipamp.ttf \
			${FILESDIR}/fonts.dir.ipa \
			${FILESDIR}/fonts.alias.ipa \
			${PREFIX}/${FONTSDIR}
	${MKDIR} ${LOCALBASE}/${LOCALFONTSDIR}
	${LN} -s -f \
		${PREFIX}/${FONTSDIR}/ipag.ttf \
		${LOCALBASE}/${LOCALFONTSDIR}/ipag.ttf
	${LN} -s -f \
		${PREFIX}/${FONTSDIR}/ipagp.ttf \
		${LOCALBASE}/${LOCALFONTSDIR}/ipagp.ttf
	${LN} -s -f \
		${PREFIX}/${FONTSDIR}/ipagui.ttf \
		${LOCALBASE}/${LOCALFONTSDIR}/ipagui.ttf
	${LN} -s -f \
		${PREFIX}/${FONTSDIR}/ipam.ttf \
		${LOCALBASE}/${LOCALFONTSDIR}/ipam.ttf
	${LN} -s -f \
		${PREFIX}/${FONTSDIR}/ipamp.ttf \
		${LOCALBASE}/${LOCALFONTSDIR}/ipamp.ttf

.for F in ${DOC_FILES}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${F} ${DOCSDIR}
.endfor
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
