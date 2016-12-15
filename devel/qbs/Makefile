# $FreeBSD$

PORTNAME=	qbs
PORTVERSION=	1.7.0
DISTVERSIONPREFIX=	src-
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	KDE/Qt/qbs

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Build Suite

LICENSE=	GPLv3 LGPL21
LICENSE_COMB=	dual

USES=		compiler:c++11-lib qmake:outsource
USE_GL=		gl
USE_LDCONFIG=	yes
USE_QT5=	buildtools_build core concurrent gui network script testlib \
		widgets xml

QMAKE_SOURCE_PATH=	${WRKSRC}/qbs.pro

OPTIONS_DEFINE=		DOCS
DOCS_USE=		QT5=help_build,qdoc_build,sql-sqlite3_build
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

.include <bsd.port.mk>
