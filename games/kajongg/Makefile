# New ports collection Makefile for:	kajongg
# Date created:				3 September 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kajongg
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=	kdegames-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Ancient Chinese board game for KDE 4

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtSql.so:${PORTSDIR}/databases/py-qt4-sql \
		ogg123:${PORTSDIR}/audio/vorbis-tools

CONFLICTS=	kdegames-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix pykde4 automoc4
KDE4_BUILDENV=	yes
USE_PYTHON=	yes
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build
USE_SQLITE=	3
USE_TWISTED_RUN=	yes
DISTINFO_FILE=	${PORTSDIR}/games/kdegames4/distinfo
USE_BZIP2=	yes
CMAKE_ARGS+=	-DINSTALL_KAJONGG:BOOL=TRUE

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

.include <bsd.port.mk>
