# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	pinot
PORTVERSION=	1.06
PORTREVISION=	8
CATEGORIES=	deskutils
MASTER_SITES=	GOOGLE_CODE
#MASTER_SITES=	http://colinf.chez.com/pinot/
#		http://amra.dyndns.org/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Personal search and metasearch for the Free Desktop

LICENSE=	GPLv2

BUILD_DEPENDS=	update-desktop-database:${PORTSDIR}/devel/desktop-file-utils
LIB_DEPENDS=	libxapian.so:${PORTSDIR}/databases/xapian-core		\
		libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24	\
		libexttextcat-2.0.so:${PORTSDIR}/textproc/libexttextcat	\
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib		\
		libxml\+\+-2.6.so:${PORTSDIR}/textproc/libxml++26	\
		libboost_thread.so:${PORTSDIR}/devel/boost-libs		\
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo		\
		libexif.so:${PORTSDIR}/graphics/libexif			\
		libexiv2.so:${PORTSDIR}/graphics/exiv2			\
		libgmime-2.4.so:${PORTSDIR}/mail/gmime24		\
		libtag.so:${PORTSDIR}/audio/taglib			\
		libcurl.so:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info	\
		antiword:${PORTSDIR}/textproc/antiword			\
		xdg-open:${PORTSDIR}/devel/xdg-utils			\
		${LOCALBASE}/libexec/xpdf/pdftotext:${PORTSDIR}/graphics/xpdf	\
		catppt:${PORTSDIR}/textproc/catdoc			\
		unzip:${PORTSDIR}/archivers/unzip			\
		unrtf:${PORTSDIR}/textproc/unrtf			\
		catdvi:${PORTSDIR}/print/catdvi

PROJECTHOST=	${PORTNAME}-search

LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-http=curl --with-ssl=${OPENSSLBASE} --enable-libarchive	\
		--enable-mempool=no
CONFIGURE_ENV=	MKDIR_P="${MKDIR}"
CPPFLAGS+=	-I${LOCALBASE}/include

USES=		gettext pkgconfig shebangfix
USE_OPENSSL=	yes
USE_PYTHON=	yes
USE_SQLITE=	3
USE_XORG=	pixman
USE_LDCONFIG=	${PREFIX}/lib/pinot/backends ${PREFIX}/lib/pinot/filters
SHEBANG_LANG=	bash
SHEBANG_FILES=	scripts/bash/*.sh

OPTIONS_DEFINE=	DEBUG CHMLIB DOCS
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ON=	--enable-debug=yes

CHMLIB_CONFIGURE_ON=	--enable-chmlib=yes
CHMLIB_CONFIGURE_OFF=	--disable-chmlib
CHMLIB_LIB_DEPENDS=	libchm.so:${PORTSDIR}/misc/chmlib

INSTALLS_ICONS=	yes

DOCS=		AUTHORS ChangeLog ChangeLog-dijon INSTALL NEWS README TODO

LM2FIX=		textcat_conf.txt textcat3_conf.txt textcat31_conf.txt textcat32_conf.txt
SHR2FIX=	Core/pinot-search.1 README
UL2FIX=		Utils/xdgmime/xdgmime.c

post-extract:
# remove pre-generated messages catalogs
	${FIND} ${WRKSRC}/po -name "*.gmo" -delete

post-patch:
	${REINPLACE_CMD} -e \
		'/<command>/s|pdftotext|${LOCALBASE}/libexec/xpdf/pdftotext|' \
		${WRKSRC}/Tokenize/filters/external-filters.xml

pre-configure:
	${REINPLACE_CMD} -e 's|-lthr|${PTHREAD_LIBS}|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|'	\
		${LM2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e 's|libtextcat/|libtextcat/LM/|'	\
		${WRKSRC}/textcat_conf.txt
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|'	\
		${UL2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|'	\
		${SHR2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e 's|Icon=pinot.png|Icon=pinot|g' \
		${WRKSRC}/*.desktop

post-install:
	${TOUCH} ${STAGEDIR}${DATADIR}/stopwords/.empty_file
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
