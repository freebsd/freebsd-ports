# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/graphics/eog-plugins/Makefile,v 1.14 2010/09/04 18:09:30 kwm Exp $

PORTNAME=	eog-plugins
PORTVERSION=	2.30.1
PORTREVISION=	7
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plug-ins for the Eye of GNOME image viewer application

BUILD_DEPENDS=	eog:${PORTSDIR}/graphics/eog
LIB_DEPENDS=	libgdata.so:${PORTSDIR}/devel/libgdata
RUN_DEPENDS=	eog:${PORTSDIR}/graphics/eog

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_GL=		gl
USE_GNOME=	gnomeprefix intlhack gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CHAMPLAIN) || \
    (exists(${LOCALBASE}/lib/libchamplain-0.8.so)) || defined(WITH_CHAMPLIAN)
LIB_DEPENDS+=	libchamplain-0.8.so:${PORTSDIR}/graphics/libchamplain
PLIST_SUB+=	CHAMPLAIN=""
.else
PLUST_SUB+=	CHAMPLAIN="@comment "
.endif

.if !defined(WITHOUT_EXIF) || (exists(${LOCALBASE}/lib/libexif.so.12) || \
	defined(WITH_EXIF))
LIB_DEPENDS+=	libexif.so:${PORTSDIR}/graphics/libexif
PLIST_SUB+=	EXIF=""
.else
PLIST_SUB+=	EXIF="@comment "
.endif

.if ${HAVE_GNOME:Mpygnome2}!=""
USE_GNOME+=	pygnome2
CONFIGURE_ARGS+=--enable-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|champlain-0.4|champlain-0.8|g' \
		-e 's|champlain-gtk-0.4|champlain-gtk-0.8|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
