PORTNAME=	fbreader
PORTVERSION=	0.99.6
DISTVERSIONSUFFIX=	-freebsdport
PORTREVISION=	8
CATEGORIES=	deskutils

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Powerful e-book reader
WWW=		https://fbreader.org/

LICENSE=	GPLv2+

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libfribidi.so:converters/fribidi \
		libunibreak.so:textproc/libunibreak

FLAVORS=	gtk2 qt6
FLAVOR?=	${FLAVORS:[1]}

USES=		compiler gmake iconv localbase pkgconfig sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	geometer
GH_PROJECT=	FBReader
USE_LDCONFIG=	yes

.if defined(WITH_DEBUG)
STATUS=		debug
.else
STATUS=		release
.endif

MAKE_ARGS+=	MAKE=${MAKE_CMD} LIBDIR=${PREFIX}/lib
MAKE_ENV+=	TARGET_ARCH=desktop TARGET_STATUS=${STATUS} ROOTDIR=${WRKSRC} \
		INSTALLDIR=${PREFIX} LIBDIR=${PREFIX}/lib LD="${CXX}"

INSTALL_TARGET=	do_install

PORTSCOUT=	ignore:1

.if ${FLAVOR} == gtk2
LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng16.so:graphics/png
USES+=		gnome jpeg
USE_GNOME=	cairo gdkpixbuf2 gtk20
MAKE_ENV+=	UI_TYPE=gtk
CONFLICTS=	${PORTNAME}-qt6
PLIST_SUB=	UITYPE=gtk
.else
PKGNAMESUFFIX=	-qt6
USES+=		qt:6
USE_QT=		base tools:build
MAKE_ENV+=	UI_TYPE=qt4
CONFLICTS=	${PORTNAME}
PLIST_SUB=	UITYPE=qt4
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^CC/d;/^LD/d;/QTINCLUDE/s,-I.*$$,-I${QT_INCDIR},' \
		${WRKSRC}/makefiles/arch/desktop.mk
	@${REINPLACE_CMD} -e 's,-O3,,;s,-ldl,${ICONV_LIB},' \
		${WRKSRC}/makefiles/config.mk ${WRKSRC}/zlibrary/core/Makefile
	@${REINPLACE_CMD} -e 's/-llinebreak/-lunibreak/g' ${WRKSRC}/zlibrary/text/Makefile
	@${REINPLACE_CMD} -e 's/-llinebreak/-lunibreak/g' ${WRKSRC}/makefiles/*.mk
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},' ${WRKSRC}/fbreader/desktop/Makefile
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} \
		-e 's,make ,$$(MAKE) ,' -e '/$$(LDFLAGS)/s/$$/ $$(LIBS)/'
	@${REINPLACE_CMD} -e '/libexec/s,libexec,${PREFIX}/libexec,' \
		${WRKSRC}/makefiles/arch/desktop.mk

pre-configure:
# This cannot be done in post-patch because build dependencies are installed
# after patching and they can pull in libiconv which can affect CFLAGS in
# Mk/Uses/iconv.mk.
	@${REINPLACE_CMD} 's|^CFLAGS =.*$$|CFLAGS = ${CFLAGS}|' \
		${WRKSRC}/makefiles/arch/desktop.mk

.include <bsd.port.mk>
