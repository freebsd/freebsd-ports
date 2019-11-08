# Created by: David Le Brun <david@dyn-ns.net>
# $FreeBSD$

PORTNAME=	gtkpod
PORTVERSION=	1.0.0
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GUI for Apple iPod using GTK2

LICENSE=	GPLv2

LIB_DEPENDS=	libid3tag.so:audio/libid3tag \
		libgpod.so:audio/libgpod

USES=		gettext gmake gnome pkgconfig python:run shebangfix
SHEBANG_FILES=	scripts/mab2vcard scripts/sync-evolution.sh \
		scripts/sync-knotes.sh scripts/sync-ldif.sh \
		scripts/sync-palm-jppy.py
USE_GNOME=	gtk20 intltool libglade2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

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

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
