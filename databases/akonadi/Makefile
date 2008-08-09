# New ports collection Makefile for:	akonadi
# Date created:				2008-01-20
# Whom:					miwi
#
# $FreeBSD$

PORTNAME=	akonadi
PORTVERSION=	1.0.0
CATEGORIES=	databases kde ipv6
MASTER_SITES=	http://akonadi.omat.nl/
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Storage server for kdepim

BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/lib/qt4/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt4-mysql-plugin \
		${LOCALBASE}/bin/mysqld_safe:${PORTSDIR}/databases/mysql${MYSQL_VER}-server
RUN_DEPENDS+=	update-mime-database:${PORTSDIR}/misc/shared-mime-info \
		${LOCALBASE}/bin/mysqld_safe:${PORTSDIR}/databases/mysql${MYSQL_VER}-server

USE_BZIP2=	yes
USE_QT_VER=	4
USE_XORG=	x11
QT_COMPONENTS=	corelib network qtestlib moc rcc uic qmake dbus
USE_MYSQL=	yes
USE_KDE4=	kdeprefix kdehier automoc4 sharedmime
KDE4_BUILDENV=	yes
PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
#fix finding automoc when PREFIX is not matched KDE4_PREFIX
	${REINPLACE_CMD} -e 's|NO_DEFAULT_PATH|${KDE4_PREFIX} NO_DEFAULT_PATH|' \
		${WRKSRC}/../cmake/modules/FindAutomoc4.cmake
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
	${REINPLACE_CMD} -e 's| MYSQLD_EXECUTABLE mysqld | MYSQLD_EXECUTABLE mysqld_safe /usr/local/bin |g' \
		${PATCH_WRKSRC}/server/CMakeLists.txt
	#prevent updating mime during build
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/d; /SharedMimeInfo/d' \
		${PATCH_WRKSRC}/CMakeLists.txt

post-install:
	@-update-mime-database ${KDE4_PREFIX}/share/mime

.include <bsd.port.mk>
