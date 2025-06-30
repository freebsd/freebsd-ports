PORTNAME=	pinot
PORTVERSION=	1.22
PORTREVISION=	4
CATEGORIES=	deskutils

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Personal search and metasearch for the Free Desktop
WWW=		https://github.com/FabriceColin/pinot/

LICENSE=	GPLv2

BUILD_DEPENDS=	desktop-file-install:devel/desktop-file-utils	\
		update-mime-database:misc/shared-mime-info
LIB_DEPENDS=	libxapian.so:databases/xapian-core		\
		libfontconfig.so:x11-fonts/fontconfig		\
		libfreetype.so:print/freetype2			\
		libexttextcat-2.0.so:textproc/libexttextcat	\
		libdbus-1.so:devel/dbus				\
		libxml++-3.0.so:textproc/libxml++30		\
		libboost_thread.so:devel/boost-libs		\
		libharfbuzz.so:print/harfbuzz			\
		libnotify.so:devel/libnotify			\
		libexif.so:graphics/libexif			\
		libexiv2.so:graphics/exiv2			\
		libgmime-2.6.so:mail/gmime26			\
		libtag.so:audio/taglib				\
		libcurl.so:ftp/curl
RUN_DEPENDS=	update-mime-database:misc/shared-mime-info	\
		antiword:textproc/antiword			\
		xdg-open:devel/xdg-utils			\
		catppt:textproc/catdoc				\
		unrtf:textproc/unrtf				\
		catdvi:print/catdvi				\
		bash:shells/bash				\
		${LOCALBASE}/libexec/xpdf/pdftotext:graphics/xpdf

USE_GITHUB=	yes
GH_ACCOUNT=	FabriceColin

USES=		compiler:c++11-lang autoreconf gettext gnome libarchive	\
		libtool pkgconfig python shebangfix sqlite:3 ssl xorg
USE_CXXSTD=	c++11
USE_XORG=	pixman
USE_GNOME=	atkmm cairo cairomm gdkpixbuf glibmm gtk30 gtkmm30	\
		libsigc++20 libxml2 pangomm
USE_LDCONFIG=	${PREFIX}/lib/pinot/backends ${PREFIX}/lib/pinot/filters
SHEBANG_FILES=	scripts/bash/*.sh

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-http=curl --with-ssl=${OPENSSLBASE} --enable-libarchive	\
		--enable-mempool=no --enable-libnotify
CONFIGURE_ENV=	MKDIR_P="${MKDIR}" TEXTCAT_LIBS="-lexttextcat-2.0"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lboost_system

OPTIONS_DEFINE=	DEBUG CHMLIB DOCS
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ON=	--enable-debug=yes

CHMLIB_DESC=		Support of Microsoft ITSS/CHM files
CHMLIB_CONFIGURE_ON=	--enable-chmlib=yes
CHMLIB_CONFIGURE_OFF=	--disable-chmlib
CHMLIB_LIB_DEPENDS=	libchm.so:misc/chmlib

INSTALL_TARGET=	install-strip
DOCS=		AUTHORS ChangeLog ChangeLog-dijon INSTALL NEWS README TODO

LM2FIX=		Core/pinot-index.cpp Core/pinot-index.1 Makefile.am	\
		textcat31_conf.txt aclocal.m4 textcat3_conf.txt	\
		textcat_conf.txt textcat32_conf.txt
SHR2FIX=	Core/pinot-search.1
UL2FIX=		Utils/xdgmime/xdgmime.c

pre-configure:
	${REINPLACE_CMD} -e \
		'/<command>/s|pdftotext|${LOCALBASE}/libexec/xpdf/pdftotext|' \
		${WRKSRC}/Tokenize/filters/external-filters.xml
	${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|'	\
		${LM2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|'	\
		${SHR2FIX:S|^|${WRKSRC}/|}

post-install:
	${TOUCH} ${STAGEDIR}${DATADIR}/stopwords/.empty_file

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
