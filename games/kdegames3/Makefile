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
GNU_CONFIGURE=	yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib

CONFIGURE_ARGS=	--disable-setgid

post-patch:
	@${REINPLACE_CMD} -e 's|root:root|${BINOWN}:${BINGRP}|g' \
				${WRKSRC}/kgoldrunner/gamedata/Makefile.in

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.mk>
