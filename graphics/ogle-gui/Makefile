# New ports collection makefile for:	ogle
# Date created:				Tue Oct 16 18:35:39 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogle
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/
PKGNAMESUFFIX=	-gui
DISTNAME=	${PORTNAME}_gui-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/ogle/libdvdcontrol.so.5:${PORTSDIR}/graphics/ogle
LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		giconv.2:${PORTSDIR}/converters/libiconv \
		glade.4:${PORTSDIR}/devel/libglade \
		xml2.5:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	ogle:${PORTSDIR}/graphics/ogle

USE_X_PREFIX=	yes
USE_GTK=	yes
USE_XPM=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-dvd-includes=${LOCALBASE}/include \
		--with-dvdcontrol=${LOCALBASE} \
		--without-included-gettext \
		--with-gtk-prefix=${X11BASE} \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-libglade-config=${X11BASE}/bin/libglade-config \
		--with-xml-prefix=${LOCALBASE}

.include <bsd.port.pre.mk>

.ifdef(HAVE_GNOME)
USE_GNOME=	yes
SHARE_DATADIR=	share/gnome
.else
SHARE_DATADIR=	share
.endif

PLIST_SUB=	SHARE_DATADIR="${SHARE_DATADIR}"

post-patch:
	@${PERL} -pi -e "s|(libglade\.so)\.0|\1.4|; \
		s|(PACKAGE_PIXMAPS_DIR=\"$${prefix}/)share(/ogle_gui/\")|\1${SHARE_DATADIR}\2|; \
		s!(CONFIG_FILE(\s|=)\")[^/]+?/!\1${LOCALBASE}/!; \
		s|(CONFIG_FILE_DTD=\")[^/]+?/|\1${LOCALBASE}/|g; \
		s|(PACKAGE_PIXMAPS_DIR=\").+\"|\1${PREFIX}/${SHARE_DATADIR}/ogle_gui/\"|; \
		s|%%LOCALBASE%%|${LOCALBASE}|" \
			${CONFIGURE_WRKSRC}/configure

post-configure:
	@${LN} -sf ${LOCALBASE}/bin/libtool ${WRKSRC}

.include <bsd.port.post.mk>
