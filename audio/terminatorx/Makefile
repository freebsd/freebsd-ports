# New ports collection Makefile for: 	terminatorx
# Date created:			13 May 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	terminatorx
PORTVERSION=	3.73
CATEGORIES=	audio
MASTER_SITES=	http://www.terminatorx.cx/
DISTNAME=	terminatorX-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2
BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USE_GNOMENG=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehier gnomelibs
CONFIGURE_ARGS+=	--disable-gtk2

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SOX)
BUILD_DEPENDS+=		sox:${PORTSDIR}/audio/sox
CONFIGURE_ARGS+=	--enable-sox
.endif
.if !defined(WITHOUT_VORBIS)
BUILD_DEPENDS+=		oggenc:${PORTSDIR}/audio/vorbis-tools
CONFIGURE_ARGS+=	--enable-vorbis
.endif
.if !defined(WITHOUT_MAD)
LIB_DEPENDS+=		mad.1:${PORTSDIR}/audio/mad
CONFIGURE_ARGS+=	--enable-mad
.endif

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	terminatorX.1

pre-everything:
.if !defined(WITHOUT_SOX)
	@${ECHO_MSG} "You can disable support for sox by defining WITHOUT_SOX."
.endif
.if !defined(WITHOUT_VORBIS)
	@${ECHO_MSG} "You can disable support for vorbis by defining WITHOUT_VORBIS."
.endif
.if !defined(WITHOUT_MAD)
	@${ECHO_MSG} "You can disable support for mad by defining WITHOUT_MAD."
.endif

post-patch:
	${REINPLACE_CMD} -e "s,function option_info,option_info," ${WRKSRC}/configure
	${REINPLACE_CMD} -e "s,malloc.h,stdlib.h," ${WRKSRC}/src/main.cc \
		${WRKSRC}/src/tX_audiofile.cc ${WRKSRC}/src/tX_flash.c \
		${WRKSRC}/src/tX_seqpar.cc ${WRKSRC}/src/tX_vtt.cc \
		${WRKSRC}/src/tX_widget.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/terminatorX ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/terminatorX.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/gnome-support/terminatorX-mime.png ${WRKSRC}/gnome-support/terminatorX-app.png ${PREFIX}/share/gnome/pixmaps
	${INSTALL_DATA} ${WRKSRC}/gnome-support/terminatorX.mime ${WRKSRC}/gnome-support/terminatorX.keys  ${PREFIX}/share/gnome/mime-info
	${INSTALL_DATA} ${WRKSRC}/gnome-support/terminatorX.desktop ${PREFIX}/share/gnome/apps/Multimedia/terminatorX.desktop

.include <bsd.port.post.mk>
