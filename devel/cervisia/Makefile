# New ports collection Makefile for: cervisia
# Version required:	0.2.1
# Date created:         17 Nov 1999
# Whom:                 Will Andrews <andrews@technologist.com>
#
# $FreeBSD$

DISTNAME=	cervisia-0.2.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/unstable/apps/utils/

MAINTAINER=	andrews@technologist.com

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11
RUN_DEPENDS=	kwm:${PORTSDIR}/x11/kdebase11

USE_QT=		yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-extra-includes="${LOCALBASE}/include" \
		--with-extra-libraries="${LOCALBASE}/lib"
CONFIGURE_ENV=	prefix="${PREFIX}" KDEDIR="${LOCALBASE}"

MAN1=		cervisia.1

.include <bsd.port.mk>
