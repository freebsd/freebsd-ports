# -*-mode: makefile-*-
# New ports collection makefile for:	aRts
# Date created:				18 February 2002
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	arts
PORTVERSION=	1.2.1
PORTEPOCH=	1
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${KDE_VERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Audio system for the KDE integrated X11 desktop

LIB_DEPENDS+=	audiofile:${PORTSDIR}/audio/libaudiofile \
		mad:${PORTSDIR}/audio/libmad \
		ogg:${PORTSDIR}/audio/libogg \
		glib:${PORTSDIR}/devel/glib20 \
		vorbis:${PORTSDIR}/audio/libvorbis

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

.include <bsd.port.mk>
