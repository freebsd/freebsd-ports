# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	mp3splt-gtk
PORTVERSION=	0.8.1
CATEGORIES=	audio
MASTER_SITES=	SF/mp3splt/${PORTNAME}/${PORTVERSION}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Utility to split mp3 and ogg files (via GTK Interface)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	mp3splt:${PORTSDIR}/audio/libmp3splt \
		mad:${PORTSDIR}/audio/libmad \
		ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis \
		id3tag:${PORTSDIR}/audio/libid3tag

INSTALLS_OMF=	yes
USE_AUTOTOOLS=	libltdl
USE_GSTREAMER=	yes
USE_GNOME=	gnomedocutils gtk20
GNU_CONFIGURE=	yes
USES=		gmake

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
# disable audacious, because gtk 3 is required to enable it for this program...
CONFIGURE_ARGS+=	--disable-audacious --with-mp3splt=${LOCALBASE} \
		--with-mp3splt-includes=${LOCALBASE}/include \
		--with-mp3splt-libraries=${LOCALBASE}/lib --disable-mp3splttest \
		--disable-gtk3

MAN1=		mp3splt-gtk.1
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
LIB_DEPENDS+=	gvc:${PORTSDIR}/graphics/graphviz
BUILD_DEPENDS+=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
.else
CONFIGURE_ARGS+=	--disable-doxygen-doc
.endif

.if ! ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USES+=		gettext
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
