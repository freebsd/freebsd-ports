# New ports collection makefile for:	freeamp
# Date Created:				26 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	freeamp
PORTVERSION=	2.1.1
CATEGORIES=	audio
MASTER_SITES=	http://www.freeamp.org/download/src/

MAINTAINER=	ports@geeksrus.net

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	musicbrainz.1:${PORTSDIR}/audio/musicbrainz \
		ORBit.2:${PORTSDIR}/devel/ORBit \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		ttf.4:${PORTSDIR}/print/freetype

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_BZIP2=	yes
USE_GTK=	yes
USE_GMAKE=	yes
USE_AUTOCONF_VER=213
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CFLAGS+=	"-D_M_IX86"
.elif ${ARCH} == "alpha"
CFLAGS+=	"-D_M_ALPHA"
.endif

.if defined(WITH_ESOUND) || defined(WITH_ALL_PLUGINS)
USE_ESOUND=	yes
PLIST_SUB+=	ESOUND=""
.else
CONFIGURE_ARGS+=	--disable-esd
PLIST_SUB+=	ESOUND="@comment "
.endif

.if defined(WITH_LIBARTS) || defined(WITH_ALL_PLUGINS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/x11/kdelibs2
PLIST_SUB+=	LIBARTS=""
.else
CONFIGURE_ARGS+=	--disable-arts
PLIST_SUB+=	LIBARTS="@comment "
.endif

.if defined(WITH_VORBIS) || defined(WITH_ALL_PLUGINS)
LIB_DEPENDS+=	vorbis.1:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=	--disable-vorbis
PLIST_SUB+=	VORBIS="@comment "
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG}
	@${ECHO_MSG} "WITH_ESOUND=yes       build with ESounD outout plugin"
	@${ECHO_MSG} "WITH_LIBARTS=yes      build with libArts output plugin"
	@${ECHO_MSG} "WITH_VORBIS=yes       build with Ogg/Vorbis codec plugin"
	@${ECHO_MSG}
	@${ECHO_MSG} "WITH_ALL_PLUGINS=yes  build with all plugins"
	@${ECHO_MSG}

post-install:
	@${MKDIR} ${PREFIX}/etc/sdr/plugins
	${INSTALL_DATA} ${FILESDIR}/sdr2.plugin.S100.audio.rtp.mpa.freeamp \
		${PREFIX}/etc/sdr/plugins
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/freeamp

.include <bsd.port.post.mk>
