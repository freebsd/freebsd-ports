# $FreeBSD$

PORTNAME=	qbs
DISTVERSIONPREFIX=	src-
DISTVERSION=	1.16.0
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	KDE/Qt/qbs

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qbs Build Suite

LICENSE=	GPLv3 LGPL21
LICENSE_COMB=	dual

USES=		compiler:c++11-lib gl python:run qmake:outsource qt:5 shebangfix
USE_GL=		gl
USE_LDCONFIG=	yes
USE_QT=		buildtools_build core concurrent gui network script testlib \
		widgets xml

SHEBANG_FILES=	src/3rdparty/python/bin/dmgbuild

QMAKE_ARGS=		CONFIG+=qbs_disable_rpath \
			CONFIG+=qbs_enable_project_file_updates
QMAKE_SOURCE_PATH=	${WRKSRC}/qbs.pro

OPTIONS_DEFINE=		DOCS
DOCS_USES=	qt:5
DOCS_USE=		QT=help_build,qdoc_build,sql-sqlite3_build
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

ALL_TARGET=		all
INSTALL_TARGET=		install

DOCS_ALL_TARGET=	docs
DOCS_INSTALL_TARGET=	install_docs

PLIST_SUB=		SHLIB_VERSION="${PORTVERSION}"

pre-configure:
# We piggyback on QMAKE_LIBDIR_FLAGS to make sure -L${WRKSRC}/lib is passed to
# the linker before -L/usr/local/lib. By default, the opposite happens, which
# is a problem when a Qt port is being upgraded, since an existing library
# would end up being picked up instead of those built in ${WRKSRC}/lib. Since
# qmake appends the value of QMAKE_LIBDIR to QMAKE_LIBDIR_FLAGS, we can use the
# latter to get the linker path order right. qmake is smart enough to strip
# occurrences of ${WRKSRC}/lib from .pc and .prl files when installing them.
# See QTBUG-40825 and ports bugs 194088, 195105 and 198720.
	${MKDIR} ${CONFIGURE_WRKSRC}
	${ECHO_CMD} 'QMAKE_LIBDIR_FLAGS = -L${CONFIGURE_WRKSRC}/lib' >> ${CONFIGURE_WRKSRC}/.qmake.cache

# The file in question is not used on FreeBSD. To silence stage-qa, remove it from stage-dir.
post-install:
	${RM} ${STAGEDIR}${DATADIR}/modules/bundle/update-specs.sh

.include <bsd.port.mk>
