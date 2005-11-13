# New ports collection makefile for:	IPA TrueType fonts
# Date created:		18 July 2004
# Whom:			NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ipa-ttfonts
PORTVERSION=	1.0.20040814
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanese TrueType fonts distributed by IPA

RUN_DEPENDS=	${LOCALBASE}/${GRASS_FONTSDIR}/ipam.ttf:${PORTSDIR}/databases/grass-i18n \
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install

SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts/TrueType
GRASS_FONTSDIR=	grass5/fonts

USE_X_PREFIX=	yes

PLIST_SUB=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR} \
		FONTSDIR_EXTRA=${PREFIX}/${X_FONTSDIR}/fonts.dir.ipa \
		LOCAL_FONTSDIR=${LOCALBASE}/${LOCAL_FONTSDIR} \
		GRASS_FONTSDIR=${LOCALBASE}/${GRASS_FONTSDIR}

do-install:
	${MKDIR} ${LOCALBASE}/${LOCAL_FONTSDIR}/TrueType
	${MKDIR} ${PREFIX}/${X_FONTSDIR}
	${LN} -s -f \
		${LOCALBASE}/${GRASS_FONTSDIR}/ipa*.ttf \
		${LOCALBASE}/${LOCAL_FONTSDIR}/TrueType/
	${LN} -s -f \
		${LOCALBASE}/${GRASS_FONTSDIR}/ipa*.ttf \
		${PREFIX}/${X_FONTSDIR}/
	${MKDIR} ${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${FILESDIR}/2.ipa-ttfonts.conf \
		${PREFIX}/etc/fonts/conf.d

post-install:
	${X11BASE}/bin/fc-cache -f -v ${PREFIX}/${X_FONTSDIR}
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
