# New ports collection makefile for:	gtkpod
# Date created: 			28 January 2003
# Whom: 				David Le Brun <david@dyn-ns.net>
#
# $FreeBSD$
#

PORTNAME=	gtkpod
PORTVERSION=	0.99.12
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GUI for Apple iPods using GTK2

LIB_DEPENDS=	id3tag.0:${PORTSDIR}/audio/libid3tag \
		gpod.5:${PORTSDIR}/audio/libgpod
RUN_DEPENDS=	mp3gain:${PORTSDIR}/audio/mp3gain \
		iconv:${PORTSDIR}/converters/libiconv

BROKEN=		does not build

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2 libgnomecanvas
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
WANT_GNOME=	yes

OPTIONS=	MPEG4IP	 "Enable AAC and H.264 support with MPEG4IP"	off \
		VORBIS	 "Enable Ogg/Vorbis support"			on \
		FLAC	 "Enable FLAC support"				on \
		GNOMEVFS "Enable iPod autodetection support"		off \
		HAL	 "Enable HAL support"				off \
		CURL	 "Build with coverart download support"		off

.include <bsd.port.pre.mk>

.if defined(WITH_MPEG4IP) || exists(${LOCALBASE}/lib/libmp4v2.so)
LIB_DEPENDS+=	mp4v2.0:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2
.endif

.if defined(WITH_VORBIS) || exists(${LOCALBASE}/lib/libvorbis.so)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
.endif

.if defined(WITH_FLAC) || exists(${LOCALBASE}/lib/libFLAC.so)
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
.endif

.if defined(WITH_GNOMEVFS) || ${HAVE_GNOME:Mgnomevfs2}
USE_GNOME+=	gnomevfs2
.endif

.if defined(WITH_HAL) || exists(${LOCALBASE}/lib/libhal.so)
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
.endif

.if defined(WITH_CURL) || exists(${LOCALBASE}/lib/libcurl.so)
LIB_DEPENDS+=	curl.5:${PORTSDIR}/ftp/curl
.endif

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"

pre-configure: .SILENT
# install locale correctly (share dir instead of lib dir)
	${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ChangeLog README TODOandBUGS.txt TROUBLESHOOTING
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
