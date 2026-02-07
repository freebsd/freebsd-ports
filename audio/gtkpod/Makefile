PORTNAME=	gtkpod
PORTVERSION=	1.0.0
PORTREVISION=	16
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GUI for Apple iPod using GTK2
WWW=		http://www.gtkpod.org/

LICENSE=	GPLv2

LIB_DEPENDS=	libid3tag.so:audio/libid3tag \
		libgpod.so:audio/libgpod

USES=		gettext gmake gnome pkgconfig python:run shebangfix
SHEBANG_FILES=	scripts/mab2vcard scripts/sync-evolution.sh \
		scripts/sync-knotes.sh scripts/sync-ldif.sh \
		scripts/sync-palm-jppy.py
USE_GNOME=	gtk20 intltool libglade2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	ChangeLog NEWS README TODOandBUGS.txt TROUBLESHOOTING

OPTIONS_DEFINE=	VORBIS FLAC CURL DOCS
OPTIONS_DEFAULT=	VORBIS FLAC CURL

CURL_DESC=	Cover art download support via libcurl

VORBIS_LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis
VORBIS_CONFIGURE_OFF=	--without-ogg

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CONFIGURE_OFF=	--without-flac

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_OFF=	--without-curl

post-patch:
# Install locale files correctly (to share dir instead of lib dir)
	@${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|' \
		${WRKSRC}/configure
# FreeBSD does not have separate libdl.so
	@${REINPLACE_CMD} -e 's| -ldl||' ${WRKSRC}/src/Makefile.in
# Fix location of the <endian.h> header
	@${REINPLACE_CMD} -e 's|endian\.h|sys/&|' ${WRKSRC}/configure \
		${WRKSRC}/src/mp4file.c
# Fix the build with -fno-common (for Clang 11 and GCC 10)
	@${REINPLACE_CMD} -e '/main_window_xml/s|^|extern |' \
		${WRKSRC}/src/display.h
	@${REINPLACE_CMD} -e '51s|^|GladeXML *main_window_xml;|' \
		${WRKSRC}/src/display.c
	@${REINPLACE_CMD} -e 's|} CONF_ID|}|' ${WRKSRC}/src/confirmation.h

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
