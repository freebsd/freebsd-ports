# New ports collection makefile for:	IPA TrueType fonts
# Date created:		18 July 2004
# Whom:			NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ipa-ttfonts
PORTVERSION=	1.0.20040814
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanese TrueType fonts distributed by IPA

RUN_DEPENDS=	${LOCALBASE}/${GRASS_FONTSDIR}/ipam.ttf:${PORTSDIR}/databases/grass-i18n

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install

LOCAL_FONTSDIR=	share/fonts/TrueType
X_FONTSDIR=	lib/X11/fonts/TrueType
GRASS_FONTSDIR=	grass5/fonts

PKGINSTALL_SUB=	X_FONTSDIR=${X11BASE}/${X_FONTSDIR}
PLIST_SUB=	X_FONTSDIR=${X11BASE}/${X_FONTSDIR} \
		FONTSDIR_EXTRA=${X11BASE}/${X_FONTSDIR}/fonts.dir.ipa \
		LOCAL_FONTSDIR=${PREFIX}/${LOCAL_FONTSDIR} \
		GRASS_FONTSDIR=${LOCALBASE}/${GRASS_FONTSDIR}

pre-install:
	@${SED} ${PKGINSTALL_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/pkg-install.in \
		> ${WRKDIR}/pkg-install
	${CHMOD} +x ${WRKDIR}/pkg-install

do-install:
	${MKDIR} ${PREFIX}/${LOCAL_FONTSDIR}
	${MKDIR} ${X11BASE}/${X_FONTSDIR}
	${LN} -s -f \
		${LOCALBASE}/${GRASS_FONTSDIR}/ipa*.ttf \
		${PREFIX}/${LOCAL_FONTSDIR}/
	${LN} -s -f \
		${LOCALBASE}/${GRASS_FONTSDIR}/ipa*.ttf \
		${X11BASE}/${X_FONTSDIR}/

post-install:
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
