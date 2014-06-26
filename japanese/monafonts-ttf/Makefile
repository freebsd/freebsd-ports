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

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKDIR}/mona.ttf ${FILESDIR}/fonts.dir.mona ${STAGEDIR}${PREFIX}/${FONTSDIR}

.include <bsd.port.mk>
