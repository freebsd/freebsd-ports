# New ports collection makefile for:	freeamp
# Date Created:				26 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	zinf
PORTVERSION=	2.2.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	GTK-based MP3 player

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	musicbrainz.2:${PORTSDIR}/audio/musicbrainz \
		id3:${PORTSDIR}/audio/id3lib

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehier gdkpixbuf
WANT_GNOME=	yes
USE_PERL5=	yes
USE_FREETYPE=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_AUTOCONF_VER=213
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include/freetype1 -I${LOCALBASE}/include \
		${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CPPFLAGS+=	"-D_M_IX86"
.elif ${ARCH} == "alpha"
CPPFLAGS+=	"-D_M_ALPHA"
.endif

.if ${HAVE_GNOME:Mesound}!="" || defined(WITH_ALL_PLUGINS)
USE_GNOME+=	esound
PLIST_SUB+=	ESOUND=""
PKGNAMESUFFIX=	-esound
.else
CONFIGURE_ARGS+=	--disable-esd
PLIST_SUB+=	ESOUND="@comment "
.endif

.if defined(WITH_LIBARTS) || defined(WITH_ALL_PLUGINS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
PLIST_SUB+=	LIBARTS=""
.else
CONFIGURE_ARGS+=	--disable-arts
PLIST_SUB+=	LIBARTS="@comment "
.endif

.if !defined(WITHOUT_VORBIS) || defined(WITH_ALL_PLUGINS)
LIB_DEPENDS+=	vorbis.2:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=	--disable-vorbis
PLIST_SUB+=	VORBIS="@comment "
.endif

# Stop a flood of complaints and PRs from people who can't be bothered
# to keep their ports and packages up to date.
.if exists(${LOCALBASE}/include/freetype/freetype.h)
.error UPGRADE print/freetype TO CURRENT VERSION!
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG}
	@${ECHO_MSG} "WITH_LIBARTS	build with libArts output plugin"
	@${ECHO_MSG} "WITHOUT_GNOME=esound	do NOT build with esd support"
	@${ECHO_MSG} "WITHOUT_VORBIS	do NOT build with Ogg/Vorbis codec plugin"
	@${ECHO_MSG}
	@${ECHO_MSG} "WITH_ALL_PLUGINS=yes  build with all plugins"
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e 's|\[en_US.ISO8859-1\]||g ; \
		 s|/usr/share/pixmaps|${PREFIX}/share/gnome/pixmaps|g' \
			${WRKSRC}/installer/unix/linux/Zinf.desktop

post-install:
	@${MKDIR} ${PREFIX}/etc/sdr/plugins
	${INSTALL_DATA} ${FILESDIR}/sdr2.plugin.S100.audio.rtp.mpa.zinf \
		${PREFIX}/etc/sdr/plugins
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}

.include <bsd.port.post.mk>
