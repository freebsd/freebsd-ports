PORTNAME=	qbs
DISTVERSIONPREFIX=	src-
DISTVERSION=	1.21.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	KDE/Qt/qbs

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qbs Build Suite

LICENSE=	GPLv3 LGPL21
LICENSE_COMB=	dual

BROKEN=		does not build with clang13 or newer

USES=		cmake compiler:c++11-lib gl python:run qt:5 shebangfix
USE_GL=		gl
USE_LDCONFIG=	yes
USE_QT=		core concurrent gui network script widgets xml \
		buildtools_build testlib_build

SHEBANG_FILES=	src/3rdparty/python/bin/dmgbuild

PLIST_SUB=		SHLIB_VERSION="${PORTVERSION}"

.include <bsd.port.mk>
