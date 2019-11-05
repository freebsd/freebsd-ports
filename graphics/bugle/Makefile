# Created by: Erik Greenwald <erik@smluc.org>
# $FreeBSD$

PORTNAME=	bugle
PORTVERSION=	0.0.20100508
PORTREVISION=	16
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Debugging library for OpenGL

LICENSE=	GPLv2

LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		gl libtool pathfix perl5
USE_GL=		gl
USE_GCC=	7
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ltdl-install=no
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		FFMPEG GTK2 READLINE THREADS DOCS
OPTIONS_DEFAULT=	READLINE THREADS

FFMPEG_CONFIGURE_WITH=	lavc
FFMPEG_LIB_DEPENDS=	libavcodec.so.1:multimedia/ffmpeg
GTK2_LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext
GTK2_USES=		gnome
GTK2_USE=		gnome=gtk20
GTK2_CONFIGURE_WITH=	gtk gtkglext
READLINE_USES=		readline
READLINE_CONFIGURE_WITH=	readline
THREADS_CONFIGURE_ON=	--with-threads=pthreads
THREADS_CONFIGURE_OFF=	--with-threads=single

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFFMPEG}
BROKEN=		Does not build with ffmpeg-2.7
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|=-lpthread|=-pthread|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|/usr/X11R6|${LOCALBASE}|' ${WRKSRC}/gengl/find_header.perl

.include <bsd.port.mk>
