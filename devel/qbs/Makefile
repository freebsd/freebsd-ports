PORTNAME=	qbs
DISTVERSIONPREFIX=	src-
DISTVERSION=	3.0.1
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	KDE/Qt/qbs

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qbs Build Suite
WWW=		https://doc.qt.io/qbs/

LICENSE=	GPLv3 LGPL21
LICENSE_COMB=	dual

USES=		cmake compiler:c++20-lang gl python:run qt:6
USE_GL=		opengl
USE_LDCONFIG=	yes
USE_QT=		5compat base

CMAKE_ON=	QBS_INSTALL_MAN_PAGE

PLIST_SUB=	QBS_VER="${DISTVERSION:R}" \
		QBS_VERSION="${DISTVERSION}"

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.12.2:www/py-beautifulsoup@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}lxml5>=4.9.3:devel/py-lxml5@${PY_FLAVOR}
DOCS_USES=		python:build
DOCS_USE=		QT=tools:build
DOCS_CMAKE_BOOL=	QBS_INSTALL_HTML_DOCS \
			QBS_INSTALL_QCH_DOCS

.include <bsd.port.mk>
