# New ports collection makefile for:	xneur
# Date created:		19 January 2007
# Whom:			Alex "lissyara" Keda <admin@lissyara.su>
#
# $FreeBSD$
#

PORTNAME=	xneur
PORTVERSION=	0.9.4
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	http://dists.xneur.ru/release-${DISTVERSION}/tgz/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	admin@lissyara.su
COMMENT=	Auto keyboard switcher

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig gnomehack
USE_ICONV=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS=	--disable-static --libdir=${PREFIX}/lib/xneur
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS}"

USE_LDCONFIG=	yes

MAN1=		xneur.1
MAN5=		xneurrc.5

OPTIONS=	GSTREAMER	"Build with GStreamer sound support"	on \
		OPENAL		"Build with OpenAL sound support"	off \
		PCRE		"Build with libpcre support"		on \
		ASPELL		"Build with aspell support"		on \
		XOSD		"Build with xosd support"		off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
LDFLAGS+=	-lintl
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--with-x=no
.else
USE_XORG+=	x11
CONFIGURE_ARGS+=	--with-x
.endif

.if !defined(WITHOUT_GSTREAMER) && defined(WITH_OPENAL)
IGNORE=	please select support one of the sound library
.else
.if !defined(WITHOUT_GSTREAMER)
USE_GSTREAMER=	yes
CONFIGURE_ARGS+=	--with-sound=gstreamer
.endif
.if defined(WITH_OPENAL)
USE_OPENAL=		al
CONFIGURE_ARGS+=	--with-sound=openal
.endif
.if defined(WITHOUT_GSTREAMER) && !defined(WITH_OPENAL)
CONFIGURE_ARGS+=	--with-sound=no
.endif
.endif

.if defined(WITHOUT_PCRE)
CONFIGURE_ARGS+=	--without-pcre
.else
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
.endif

.if defined(WITHOUT_ASPELL)
CONFIGURE_ARGS+=	--without-aspell
.else
LIB_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
.endif

.if !defined(WITH_XOSD)
CONFIGURE_ARGS+=	--without-xosd
.else
LIB_DEPENDS+=	xosd.4:${PORTSDIR}/misc/xosd
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS=/s|="|="$$CFLAGS |' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^am__strip_dir/s#`;#|sed -Ee \
		"s/^(dict.dist|proto|proto3|langdef|regexp|xneurrc|xneurrc-be|xneurrc-bg|xneurrc-cs|xneurrc-el|xneurrc-es|xneurrc-et|xneurrc-kk|xneurrc-lt|xneurrc-lv|xneurrc-pl|xneurrc-uz|xneurrc-uk|xneurrc-fr|xneurrc-ro|xneurrc-de|xneurrc-kz|dict)$$$$/\\1.dist/"`;#' \
		${WRKSRC}/etc/Makefile.in ${WRKSRC}/etc/Makefile.am

post-install:
	@for i in ${PREFIX}/etc/xneur/*.dist ;\
		do ${CP} -np $$i $${i%.dist}; done

.include <bsd.port.post.mk>
