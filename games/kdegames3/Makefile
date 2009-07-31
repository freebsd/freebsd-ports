# New ports collection makefile for:	kdegames3
# Date created:				Sun 14 May 2000 02:47:57
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdegames
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	1
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Games for the KDE integrated X11 desktop

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=  libtool:15

USE_LDCONFIG=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib

CONFIGURE_ARGS=	--disable-setgid

DECKS=		${WRKSRC}/libkdegames/carddecks/decks/

.if defined(WITHOUT_TUX)
PLIST_SUB+=	FREEBSD_DECK="@comment "
.else
PLIST_SUB+=	FREEBSD_DECK=""
.endif

post-extract:
.if defined(WITHOUT_TUX)
	${CP} ${FILESDIR}/deck_freebsd.desktop ${DECKS}deck14.desktop
	${CP} ${FILESDIR}/deck_freebsd.png ${DECKS}/deck14.png
.else
	${CP} ${FILESDIR}/deck_freebsd.desktop ${DECKS}
	${CP} ${FILESDIR}/deck_freebsd.png ${DECKS}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|root:root|${BINOWN}:${BINGRP}|g' \
				${WRKSRC}/kgoldrunner/gamedata/Makefile.in

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.mk>
