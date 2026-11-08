PORTNAME=	tiled
PORTVERSION=	1.12.2
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics editors games

USE_GITHUB=	yes
GH_ACCOUNT=	bjorn

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose tile map editor
WWW=		https://www.mapeditor.org/

LICENSE=	BSD2CLAUSE BSD3CLAUSE GPLv2+ APACHE20 LGPL20
LICENSE_COMB=	multi

BUILD_DEPENDS=	qbs:devel/qbs
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		compiler:c++17-lang desktop-file-utils gl pkgconfig qt:6 \
		shared-mime-info
USE_QT=		base declarative tools:build
USE_GL=		gl
USE_LDCONFIG=	yes

QBS_SETTINGS=	${WRKDIR}/.qbs
QBS_ARGS=	--settings-dir ${QBS_SETTINGS} \
		projects.Tiled.useRPaths:false \
		qbs.installPrefix:${PREFIX} \
		qbs.buildVariant:release

OPTIONS_DEFINE=	PYTHON DBUS DOCS
OPTIONS_DEFAULT=PYTHON DBUS
OPTIONS_SUB=	yes

PYTHON_DESC=		Enable python scripting plugin
PYTHON_USES=		pkgconfig python:3.8+

DBUS_DESC=		D-Bus support (single-instance and MPRIS)

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPYTHON}
QBS_ARGS+=	projects.Tiled.pythonPkgConfigName:python-${PYTHON_VER}-embed
.else
QBS_ARGS+=	projects.Tiled.pythonPkgConfigName:disabled-python
.endif
.if !${PORT_OPTIONS:MDBUS}
QBS_ARGS+=	projects.Tiled.dbus:false
.endif

do-configure:
	@${MKDIR} ${QBS_SETTINGS}
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		qbs setup-toolchains --settings-dir ${QBS_SETTINGS} --detect
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		qbs setup-qt --settings-dir ${QBS_SETTINGS} ${QMAKE} qt6

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		qbs build --jobs ${MAKE_JOBS_NUMBER} profile:qt6 ${QBS_ARGS}

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		qbs install --install-root ${STAGEDIR} profile:qt6 ${QBS_ARGS}

post-install:
# The Qbs install target does not install the desktop integration
# files; install them manually like the old qmake build did.
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applications \
		${STAGEDIR}${PREFIX}/share/metainfo \
		${STAGEDIR}${PREFIX}/share/mime/packages \
		${STAGEDIR}${PREFIX}/share/thumbnailers \
		${STAGEDIR}${PREFIX}/share/man/man1 \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/mimetypes \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/mimetypes \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/mimetypes
	${INSTALL_DATA} ${WRKSRC}/org.mapeditor.Tiled.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/org.mapeditor.Tiled.appdata.xml \
		${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/mime/org.mapeditor.Tiled.xml \
		${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/mime/tiled.thumbnailer \
		${STAGEDIR}${PREFIX}/share/thumbnailers
	${INSTALL_DATA} ${WRKSRC}/src/tiledapp/images/16/tiled.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps
	${INSTALL_DATA} ${WRKSRC}/src/tiledapp/images/16/application-x-tiled.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/mimetypes
	${INSTALL_DATA} ${WRKSRC}/src/tiledapp/images/32/tiled.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps
	${INSTALL_DATA} ${WRKSRC}/src/tiledapp/images/32/application-x-tiled.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/mimetypes
	${INSTALL_DATA} ${WRKSRC}/src/tiledapp/images/scalable/tiled.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/src/tiledapp/images/scalable/application-x-tiled.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/mimetypes
.for m in tiled tmxrasterizer tmxviewer
	${INSTALL_MAN} ${WRKSRC}/man/${m}.1 ${STAGEDIR}${PREFIX}/share/man/man1
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS README.md NEWS.md
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.post.mk>
