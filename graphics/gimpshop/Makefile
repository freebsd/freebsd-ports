# New ports collection makefile for: GIMPshop
# Date created:		Thu Feb 16 20:45:20 BRDT 2006
# Whom:			Rainer Alves <rainer.alves@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gimpshop
PORTVERSION=	2.2.11
PORTREVISION=	5
CATEGORIES=	graphics gnome
MASTER_SITES=	http://www.plasticbugs.com/blogimg/ \
		http://freebsd.powered.net/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GIMP fork resembling Adobe Photoshop

LIB_DEPENDS=	wmf:${PORTSDIR}/graphics/libwmf \
		aa:${PORTSDIR}/graphics/aalib \
		exif:${PORTSDIR}/graphics/libexif \
		mng:${PORTSDIR}/graphics/libmng \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		tiff:${PORTSDIR}/graphics/tiff

CONFLICTS=	gimp-1.* gimp-2.* gimp-gnome-2.*

SHLIBVER?=	200

USE_BZIP2=	yes
USE_XLIB=	yes
USE_XPM=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack intltool intlhack gtk20 libartlgpl2 librsvg2
WANT_GNOME=	yes
INSTALLS_SHLIB=	yes
PLIST_SUB=	SHLIBVER="${SHLIBVER}"
CONFIGURE_ARGS=	--disable-perl \
		--with-html-dir=${DOCSDIR} \
		--disable-gtk-doc \
		--enable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

WRKSRC=		${WRKDIR}/gimp-${PORTVERSION}

MAN1=	gimp.1 gimp-2.2.1 gimp-remote.1 gimp-remote-2.2.1 gimptool-2.0.1
MAN5=	gimprc.5 gimprc-2.2.5

OPTIONS=	DEBUG "debugging" off \
		PYTHON "Python-Fu support" off \
		PRINT "GIMP printing" on \
		HTML_HELP_BROWSER "GIMP help browser" on \
		MP "multiple processor support" off

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=		yes
# we need to manually include this, because USE_PYTHON is defined
# after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.python.mk"
USE_GNOME+=		pygtk2
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=		PYTHON:=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=		PYTHON:="@comment "
.endif

.if defined(WITHOUT_PRINT)
CONFIGURE_ARGS+=	--disable-print
PLIST_SUB+=		PRINT="@comment "
.else
LIB_DEPENDS+=		gimpprint.2:${PORTSDIR}/print/gimp-print
PLIST_SUB+=		PRINT=""
.endif

.if defined(WITH_MP)
CONFIGURE_ARGS+=	--enable-mp
.endif

.if ${HAVE_GNOME:Mgnomepanel}!=""
USE_GNOME+=		gnomepanel desktopfileutils
CONFIGURE_ARGS+=	--with-desktop-dir=${LOCALBASE}/share/gnome
CONFIGURE_ENV+=		GIMP_THREAD_LIBS=${PTHREAD_LIBS}
PLIST_SUB+=		GNOMEPANEL:=""
GNOME_ENABLED=		yes
.else
PLIST_SUB+=		GNOMEPANEL:="@comment "
CONFIGURE_ENV+=		GIMP_THREAD_LIBS=${PTHREAD_LIBS}
.endif

.if defined(WITH_HTML_HELP_BROWSER)
USE_GNOME+=		libgtkhtml
PLIST_SUB+=		HELPBROWSER:=""
.else
PLIST_SUB+=		HELPBROWSER:="@comment "
post-patch:
	@${REINPLACE_CMD} -e 's|\(have_gtkhtml2=\)yes|\1no|' ${WRKSRC}/configure
.endif

.if defined(GNOME_ENABLED)
post-install:
	@-update-desktop-database
.endif

.include <bsd.port.post.mk>
