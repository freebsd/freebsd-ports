# -*-mode: makefile-*-
# New ports collection makefile for:	aRts
# Date created:				18 February 2002
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	arts
PORTVERSION=	1.1.4
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	audio kde
MASTER_SITES=	http://mirrors.isc.org/pub/kde/stable/3.1.4/FreeBSD/patches/ \
		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/3.1.4/src
DISTFILES=	arts-1.1.4.tar.bz2 \
		arts-2003092201-configure.tar.bz2 \
		patch-ltmain.sh
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Audio system for the KDE integrated X11 desktop

LIB_DEPENDS+=	audiofile.0:${PORTSDIR}/audio/libaudiofile

USE_QT_VER=	3
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
QTCPPFLAGS+=	-L${LOCALBASE}/lib
DO_NOT_COMPILE+=gmcop

CFLAGS+=	-DHAVE_VASPRINTF
CONFIGURE_ENV+=	DO_NOT_COMPILE="${DO_NOT_COMPILE}"

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

post-install:
	@${CHMOD} 4555 ${PREFIX}/bin/artswrapper	

.include <bsd.port.mk>
