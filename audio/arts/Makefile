# -*-mode: makefile-*-
# New ports collection makefile for:	aRts
# Date created:				18 February 2002
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	arts
PORTVERSION=	1.1
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${KDE_VERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile

USE_QT_VER=	3
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
QTCPPFLAGS+=	-L${LOCALBASE}/lib

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.mk>
