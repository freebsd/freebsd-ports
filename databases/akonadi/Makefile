# New ports collection Makefile for:	akonadi
# Date created:				2008-01-20
# Whom:					miwi
#
# $FreeBSD$

PORTNAME=	akonadi
PORTVERSION=	1.1.2
CATEGORIES=	databases kde ipv6
MASTER_SITES=	http://download.akonadi-project.org/
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Storage server for kdepim

LIB_DEPENDS=	boost_python:${PORTSDIR}/devel/boost-python
BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/bin/mysqld_safe:${PORTSDIR}/databases/mysql${MYSQL_VER}-server
RUN_DEPENDS=	${QT_PREFIX}/lib/qt4/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt4-mysql-plugin

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib network qtestlib dbus sql \
		qmake_build moc_build rcc_build uic_build
USE_MYSQL=	server
USE_KDE4=	kdeprefix kdehier automoc4 sharedmime
KDE4_BUILDENV=	yes
PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_JOBS_UNSAFE=	yes

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e '/akonadi.pc/s|pkgconfig|../libdata/pkgconfig|' \
		${PATCH_WRKSRC}/CMakeLists.txt
	${CP} ${PATCH_WRKSRC}/server/src/storage/entities-header.xsl \
		${PATCH_WRKSRC}/server/src/storage/entitiesKDE4.header.xsl
	cd ${PATCH_WRKSRC}/server && \
	${REINPLACE_CMD} -e 's|entities.h|entitiesKDE4.h|g' \
		CMakeLists.txt \
		src/storage/entities.xsl \
		src/storage/doxygen-preprocess-entities.sh
# graphics/gd installs entities.h to ${LOCALBASE}/include, rename kde's entities.h to fix build
.for ext in *.cpp *.h
	${FIND} ${PATCH_WRKSRC} -name ${ext} | ${XARGS} \
		${REINPLACE_CMD} -e 's|include "entities.h"|include <entitiesKDE4.h>|g' \
				-e 's|include <entities.h>|include <entitiesKDE4.h>|g'
.endfor
	${REINPLACE_CMD} -e '/find_program/s|mysqld|mysqld_safe ${LOCALBASE}/bin|g' \
		${PATCH_WRKSRC}/server/CMakeLists.txt
	#prevent updating mime during build
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/d; /SharedMimeInfo/d' \
		${PATCH_WRKSRC}/CMakeLists.txt

post-install:
	@-update-mime-database ${KDE4_PREFIX}/share/mime

.include <bsd.port.mk>
