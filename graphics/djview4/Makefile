# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	djview
PORTVERSION=	4.10.3
CATEGORIES=	graphics
MASTER_SITES=	SF/djvu/DjView/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone Djvu viewer and plugin based on Qt toolkit

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rsvg-convert:${PORTSDIR}/graphics/librsvg2
LIB_DEPENDS=	libdjvulibre.so:${PORTSDIR}/graphics/djvulibre \
		libtiff.so:${PORTSDIR}/graphics/tiff

INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
USES=		autoreconf desktop-file-utils gmake libtool pkgconfig \
		webplugin:native
USE_XORG=	sm ice xt
CONFIGURE_ARGS=	--x-includes="${LOCALBASE}/include" \
		--x-libraries="${LOCALBASE}/lib"
CONFIGURE_ENV=	LRELEASE="${LRELEASE}" LUPDATE="${LUPDATE}"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

WEBPLUGIN_DIR=		${PREFIX}/lib/djview4/plugins
WEBPLUGIN_FILES=	nsdejavu.so

OPTIONS_SINGLE=	QT
OPTIONS_SINGLE_QT=	QT4 QT5
OPTIONS_DEFAULT=	QT5

QT4_USE=	QT4=gui,network,opengl,linguisttools_build,moc_build,qmake_build,rcc_build,uic_build
QT5_USE=	QT5=gui,network,opengl,printsupport,widgets,buildtools_build,linguisttools_build,qmake_build

post-patch: .SILENT
# Change plugins directory
# Add GLIB cflags and libs (including -lX*)
	${REINPLACE_CMD} -e '/^pluginsdir/s/mozilla/djview4/ ; \
		/NSDEJAVU_CFLAGS/s|$$| $$\(GLIB_CFLAGS\)| ; \
		/NSDEJAVU_LIBS/s|$$| $$\(GLIB_LIBS\) -lXt -lXext|' \
		${WRKSRC}/nsdejavu/Makefile.am

post-install:
# Changing file write permissions needed to strip a file installed as a script
	${CHMOD} +w ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${CHMOD} -w ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
# Create a symbolic link to match desktop file exec name
	(cd ${STAGEDIR}${PREFIX}/bin && ${LN} -sf ${PORTNAME} ${PORTNAME}4)

.include <bsd.port.mk>
