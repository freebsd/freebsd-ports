# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	djview
PORTVERSION=	4.10.6
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/djvu/DjView/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone Djvu viewer and plugin based on Qt toolkit

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre \
		libtiff.so:graphics/tiff

INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
USES=		autoreconf desktop-file-utils gettext-runtime gmake libtool \
		localbase pkgconfig webplugin:native
USE_GL=		gl
USE_XORG=	sm ice xext xt
USE_GNOME=	glib20
CONFIGURE_ENV=	LRELEASE="${LRELEASE}" LUPDATE="${LUPDATE}"

WEBPLUGIN_DIR=		${PREFIX}/lib/djview4/plugins
WEBPLUGIN_FILES=	nsdejavu.so

OPTIONS_SINGLE=	QT
OPTIONS_SINGLE_QT=	QT4 QT5
OPTIONS_DEFAULT=	QT5
QT_DESC=		Qt toolkit

QT4_USES=	qt:4
QT4_USE=	QT=corelib,gui,network,opengl,linguisttools_build,moc_build,qmake_build,rcc_build,uic_build
QT4_USE+=	XORG=x11
QT5_USES=	qt:5
QT5_USE=	QT=core,gui,network,opengl,printsupport,widgets,buildtools_build,linguisttools_build,qmake_build

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

post-patch:
# Use prebuilt icons, without using conversion tool
	@${REINPLACE_CMD} -e 's/conversion_tool=[[:alpha:]]*/conversion_tool=no/' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e \
		'/CXXFLAGS=$$/s|^|#| ; \
		 /CFLAGS=$$/s|^|#| ; \
		 s|$$OPTS -O2|$$OPTS|' ${WRKSRC}/config/acinclude.m4
	@${REINPLACE_CMD} -e \
		's|FLAGS+=|FLAGS_RELEASE=|' ${WRKSRC}/src/Makefile.am
# Change plugins directory
# Add GLIB cflags and libs (including -lX*)
	@${REINPLACE_CMD} -e '/^pluginsdir/s/mozilla/djview4/ ; \
		/NSDEJAVU_CFLAGS/s|$$| $$(GLIB_CFLAGS)| ; \
		/NSDEJAVU_LIBS/s|$$| $$(GLIB_LIBS) -lXt -lXext|' \
		${WRKSRC}/nsdejavu/Makefile.am

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/djview
# Create a symbolic link to match desktop file exec name
	${LN} -sf djview ${STAGEDIR}${PREFIX}/bin/djview4

.include <bsd.port.mk>
