# Created by: Erik Greenwald <erik@smluc.org>
# $FreeBSD$

PORTNAME=	bugle
PORTVERSION=	0.0.20091026
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	A debugging library for OpenGL

OPTIONS_DEFINE=	AVCODEC GUI THREADS
AVCODEC_DESC=	LAVC codec support

GNU_CONFIGURE=	yes
USE_GL=		gl
USE_PERL5=	yes
USE_AUTOTOOLS=	libltdl
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/${PORTNAME}

CONFIGURE_ARGS=--enable-ltdl-install=no
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" \
		GL_LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

MAN1=	gldb.1 gldb-gui.1
MAN3=	bugle.3
MAN5=	bugle-statistics.5
MAN7=	bugle-camera.7 bugle-checks.7 bugle-eps.7 bugle-error.7 \
	bugle-exe.7 bugle-extoverride.7 bugle-frontbuffer.7 bugle-log.7 \
	bugle-logstats.7 bugle-screenshot.7 bugle-showerror.7 \
	bugle-showextensions.7 bugle-showstats.7 bugle-stats_basic.7 \
	bugle-stats_calls.7 bugle-stats_calltimes.7 bugle-stats_fragments.7 \
	bugle-stats_nv.7 bugle-stats_primitives.7 bugle-trace.7 \
	bugle-unwindstack.7 bugle-wireframe.7

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAVCODEC}
CONFIGURE_ARGS+=--with-lavc
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
.else
CONFIGURE_ARGS+=--without-lavc
.endif

.if ${PORT_OPTIONS:MGUI}
LIB_DEPENDS+=	gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext
CONFIGURE_ARGS+=--with-gtk --with-gtkglext
.else
CONFIGURE_ARGS+=--without-gtk --without-gtkglext
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=--with-threads=pthreads
.else
CONFIGURE_ARGS+=--with-threads=single
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Fails to link
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' ${WRKSRC}/gengl/find_header.perl

post-install:
	@${RM} -f ${PREFIX}/lib/libbugle.la ${PREFIX}/lib/libbugleutils.la \
	          ${PREFIX}/lib/bugle/*.la \
	          ${PREFIX}/lib/pkgconfig/bugle.pc
	@-${RMDIR} ${PREFIX}/lib/pkgconfig
	@${RM} -rf ${PREFIX}/share/doc/bugle

.include <bsd.port.mk>
