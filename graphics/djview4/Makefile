PORTNAME=	djview
DISTVERSION=	4.12.3
CATEGORIES=	graphics
MASTER_SITES=	SF/djvu/DjView/${DISTVERSION:R}

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Standalone Djvu viewer and plugin based on Qt toolkit
WWW=		https://djvu.sourceforge.net/djview4.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_riscv64=	fails to build: ./nsdejavu/npsdk/prcpucfg.h:751:2: Unknown CPU architecture

LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre \
		libtiff.so:graphics/tiff

USES=		autoreconf desktop-file-utils gettext-runtime gl gmake gnome \
		libtool localbase pkgconfig qt:6 xorg
USE_GL=		opengl
USE_GNOME=	glib20
USE_QT=		5compat base tools:build
USE_XORG=	xext xorgproto xt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LRELEASE="${LRELEASE}" LUPDATE="${LUPDATE}"

INSTALL_TARGET=	install-strip

BINARY_ALIAS=	qmake=${QMAKE}

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
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/djview
# Create a symbolic link to match desktop file exec name
	${RLN} djview ${STAGEDIR}${PREFIX}/bin/djview4

.include <bsd.port.mk>
