# New ports collection makefile for:	aRts
# Date created:				18 February 2002
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	arts
PORTVERSION=	${KDE_VERSION:S/3.0/1.0/g}
PORTEPOCH=	1
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${KDE_VERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile

KDE_PATCHFROM_VER=	${KDE_ORIGVER:S/3.0/1.0/g}
KDE_PATCHTO_VER=	${KDE_VERSION:S/3.0/1.0/g}
#WRKSRC=		${WRKDIR}/arts
USE_BZIP2=	yes
USE_QT_VER=	3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
QTCPPFLAGS+=	-L${LOCALBASE}/lib

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.mk>
