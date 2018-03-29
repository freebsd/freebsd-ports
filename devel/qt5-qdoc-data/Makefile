# $FreeBSD$

# While this port is part of the Qt distribution itself, we do not set
# QT_DIST=yes because it brings in several patches and targets that are not
# needed; this port only installs some static files.

PORTNAME=	qdoc-data
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	devel textproc
MASTER_SITES=	QT/official_releases/qt/${QT5_VERSION:R}/${QT5_VERSION}/submodules/
PKGNAMEPREFIX=	qt5-
DISTNAME=	qtbase-opensource-src-${QT5_VERSION}
DIST_SUBDIR=	KDE/Qt/${QT5_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QDoc configuration files

LICENSE=	GFDL
LICENSE_FILE=	${WRKSRC}/LICENSE.FDL

USES=		tar:xz
USE_QT5=	# empty

EXTRACT_AFTER_ARGS=	--include ${DISTNAME}/LICENSE.FDL \
			--include ${DISTNAME}/doc

NO_ARCH=	yes
NO_BUILD=	yes

DESCR=		${.CURDIR:H:H}/devel/qt5/pkg-descr
DISTINFO_FILE=	${.CURDIR:H:H}/devel/qt5/distinfo

do-install:
	${MKDIR} ${STAGEDIR}${QT_DOCDIR} && \
		cd ${WRKSRC}/doc/global && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/${QT_DOCDIR_REL}/global

.include <bsd.port.mk>
