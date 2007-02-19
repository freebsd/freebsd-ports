# New ports collection makefile for:	bugle
# Date created:			Jun 8, 2004
# Whom:				Erik Greenwald <erik@smluc.org>
#
# $FreeBSD$
#

PORTNAME=	bugle
PORTVERSION=	0.0.20070217
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	erik@smluc.org
COMMENT=	A debugging library for OpenGL

OPTIONS=	AVCODEC "With avcodec support (ffmpeg)" off
OPTIONS+=	GUI "With GTK support (GtkGlExt)" off
OPTIONS+=	THREADS "With threading support" off

GNU_CONFIGURE=	yes
USE_GCC=	3.4
USE_GL=		yes
USE_PERL5=	yes
USE_AUTOTOOLS=	libltdl:15
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/${PORTNAME}

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=--enable-ltdl-install=no --mandir=${MANPREFIX}/man
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		LIBS="-L${X11BASE}/lib -L${LOCALBASE}/lib" \
		GL_LIBS="-L${X11BASE}/lib"

MAN1=	gldb.1
MAN3=	bugle.3
MAN7=	bugle-camera.7 bugle-checks.7 bugle-eps.7 bugle-error.7		\
	bugle-frontbuffer.7 bugle-log.7 bugle-logstats.7		\
	bugle-screenshot.7 bugle-showerror.7 bugle-showextensions.7	\
	bugle-showstats.7 bugle-stats_basic.7 bugle-stats_fragments.7	\
	bugle-stats_nv.7 bugle-stats_primitives.7 bugle-trace.7		\
	bugle-unwindstack.7 bugle-wireframe.7

OPTIONS=	AVCODEC	"Use lavc from multimedia/ffmpeg"	off
OPTIONS+=	GUI	"Use gktglext"				off
OPTIONS+=	THREADS	"Use pthreads"				off

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.x or later to build. Install lang/perl5.8 then try again
.endif

.if defined(WITH_AVCODEC)
CONFIGURE_ARGS+=--with-lavc
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
.else
CONFIGURE_ARGS+=--without-lavc
.endif

.if defined(WITH_GUI)
LIB_DEPENDS+=	gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext
CONFIGURE_ARGS+=--with-gtk --with-gtkglext
.else
CONFIGURE_ARGS+=--without-gtk --without-gtkglext
.endif

.if defined(WITH_THREADS)
CONFIGURE_ARGS+=--with-threads=pthreads
.else
CONFIGURE_ARGS+=--with-threads=single
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${X11BASE},g' ${WRKSRC}/gentokens/find_header.perl

.include <bsd.port.post.mk>
