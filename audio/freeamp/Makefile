# New ports collection makefile for:	freeamp
# Date Created:				26 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	freeamp
PORTVERSION=	2.1.0
PORTREVISION=	2
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
WANT_ESOUND=	yes
USE_GTK=	yes
USE_GMAKE=	yes
USE_AUTOCONF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CFLAGS+=	"-D_M_IX86"
.elif ${ARCH} == "alpha"
CFLAGS+=	"-D_M_ALPHA"
.endif

.if defined(HAVE_ESOUND)
USE_ESOUND=	yes
PLIST_SUB+=	ESOUND=""
.else
CONFIGURE_ARGS+=	--disable-esd
PLIST_SUB+=	ESOUND="@comment "
.endif

.if defined(WITH_LIBARTS)
LIB_DEPENDS=	libartsc.0:${PORTSDIR}/x11/kdelibs2
PLIST_SUB+=	LIBARTS=""
.else
CONFIGURE_ARGS+=	--disable-arts
PLIST_SUB+=	LIBARTS="@comment "
.endif

post-install:
	@${MKDIR} ${PREFIX}/etc/sdr/plugins
	${INSTALL_DATA} ${FILESDIR}/sdr2.plugin.S100.audio.rtp.mpa.freeamp \
		${PREFIX}/etc/sdr/plugins

.include <bsd.port.post.mk>
