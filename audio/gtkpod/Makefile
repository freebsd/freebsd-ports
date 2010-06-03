# New ports collection makefile for:	gtkpod
# Date created: 			28 January 2003
# Whom: 				David Le Brun <david@dyn-ns.net>
#
# $FreeBSD$
#

PORTNAME=	gtkpod
PORTVERSION=	0.99.14
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GUI for Apple iPod using GTK2

LIB_DEPENDS=	id3tag.0:${PORTSDIR}/audio/libid3tag \
		gpod.5:${PORTSDIR}/audio/libgpod
RUN_DEPENDS=	mp3gain:${PORTSDIR}/audio/mp3gain \
		iconv:${PORTSDIR}/converters/libiconv

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_ICONS=	yes
WANT_GNOME=	yes
MAN1=		gtkpod.1

PORTDOCS=	ChangeLog README TODOandBUGS.txt TROUBLESHOOTING

OPTIONS=	MPEG4IP	 "Enable AAC and H.264 support with MPEG4IP"	off \
		VORBIS	 "Enable Ogg/Vorbis support (decoding)"		on \
		FLAC	 "Enable FLAC support (decoding)"		on \
		LAME	 "Enable encoding to MP3 format"		on \
		GNOMEVFS "Enable iPod autodetection support"		off \
		HAL	 "Enable HAL support"				off \
		CURL	 "Build with coverart download support"		on

.include <bsd.port.pre.mk>

.if defined(WITH_MPEG4IP) || exists(${LOCALBASE}/lib/libmp4v2.so)
LIB_DEPENDS+=	mp4v2.0:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2
# Define HAVE_GTK to unbreak the build with libmp4v2.so (it is built
# without Gtk support by default, which can result in gtkpod breakage)
MAKE_ARGS+=	CPPFLAGS="-DHAVE_GTK"
.endif
.for x in faac faad
.  if exists(${LOCALBASE}/bin/${x})
RUN_DEPENDS+=	${x}:${PORTSDIR}/audio/${x}
.  endif
.endfor

.if defined(WITH_VORBIS) || exists(${LOCALBASE}/lib/libvorbis.so)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
RUN_DEPENDS+=	oggdec:${PORTSDIR}/audio/vorbis-tools
.endif

.if defined(WITH_FLAC) || exists(${LOCALBASE}/lib/libFLAC.so)
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
.endif

.if defined(WITH_LAME) || exists(${LOCALBASE}/bin/lame)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if defined(WITH_GNOMEVFS) || ${HAVE_GNOME:Mgnomevfs2}
USE_GNOME+=	gnomevfs2
.endif

.if defined(WITH_HAL) || exists(${LOCALBASE}/lib/libhal.so)
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
.endif

.if defined(WITH_CURL) || exists(${LOCALBASE}/lib/libcurl.so)
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
.endif

pre-configure: .SILENT
# Install locale files correctly (to share dir instead of lib dir)
	${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
