# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	monafonts-ttf
PORTVERSION=	2.90
PORTREVISION=	3
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	SF/monafont/monafont/monafont-${PORTVERSION}
DISTNAME=	monafont-ttf-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	X11 TrueType Kanji fonts

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
FONTSDIR=	lib/X11/fonts/TrueType
MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}

NO_STAGE=	yes
do-install:
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	${INSTALL_DATA} ${WRKDIR}/mona.ttf ${FILESDIR}/fonts.dir.mona ${PREFIX}/${FONTSDIR}
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
