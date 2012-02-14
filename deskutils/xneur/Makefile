# New ports collection makefile for:	xneur
# Date created:		19 January 2007
# Whom:			Alex "lissyara" Keda <admin@lissyara.su>
#
# $FreeBSD$
#

PORTNAME=	xneur
PORTVERSION=	0.15.0
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://dists.xneur.ru/release-${DISTVERSION}/tgz/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	admin@lissyara.su
COMMENT=	Auto keyboard switcher

LIB_DEPENDS=	notify.4:${PORTSDIR}/devel/libnotify \
		pcre.1:${PORTSDIR}/devel/pcre

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig gnomehack
USE_ICONV=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
CONFIGURE_ARGS=	--disable-static --libdir=${PREFIX}/lib/xneur

USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

MAN1=		xneur.1
MAN5=		xneurrc.5

OPTIONS=	GSTREAMER	"Build with GStreamer sound support"	on \
		OPENAL		"Build with OpenAL sound support"	off \
		ASPELL		"Build with aspell support"		on \
		XOSD		"Build with xosd support"		off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
.else
USE_XORG+=	x11
CONFIGURE_ARGS+=	--with-x
.endif

.if !defined(WITHOUT_GSTREAMER) && defined(WITH_OPENAL)
IGNORE=	please select only one sound library
.else
.if !defined(WITHOUT_GSTREAMER)
USE_GSTREAMER=	yes
CONFIGURE_ARGS+=	--with-sound=gstreamer
.endif
.if defined(WITH_OPENAL)
USE_OPENAL=		al alut
CONFIGURE_ARGS+=	--with-sound=openal
.endif
.if defined(WITHOUT_GSTREAMER) && !defined(WITH_OPENAL)
CONFIGURE_ARGS+=	--with-sound=no
.endif
.endif

.if defined(WITHOUT_ASPELL)
CONFIGURE_ARGS+=	--with-spell=no --without-aspell
.else
LIB_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=	--with-spell=aspell
.endif

.if !defined(WITH_XOSD)
CONFIGURE_ARGS+=	--without-xosd
.else
LIB_DEPENDS+=	xosd.4:${PORTSDIR}/misc/xosd
CONFIGURE_ARGS+=	--with-xosd
.endif

post-patch:
	@${MV} ${WRKSRC}/etc/xneurrc ${WRKSRC}/etc/xneurrc.sample

post-install:
.if !exists(${PREFIX}/etc/xneur/xneurrc)
	${CP} -p ${PREFIX}/etc/xneur/xneurrc.sample ${PREFIX}/etc/xneur/xneurrc
.endif

.include <bsd.port.post.mk>
