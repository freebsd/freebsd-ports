# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	mp3splt-gtk
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/mp3splt/${PORTNAME}/${PORTVERSION}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Utility to split mp3 and ogg files (via GTK Interface)

LICENSE=	GPLv2

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: tree_columns
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: tree_columns

LIB_DEPENDS=	libmp3splt.so:audio/libmp3splt \
		libmad.so:audio/libmad \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libid3tag.so:audio/libid3tag \
		libltdl.so:devel/libltdl

USES=		desktop-file-utils gmake gnome pkgconfig
INSTALLS_OMF=	yes
USE_GSTREAMER1=	yes
USE_GNOME=	gtk30
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--disable-audacious --with-mp3splt=${LOCALBASE} \
		--with-mp3splt-includes=${LOCALBASE}/include \
		--with-mp3splt-libraries=${LOCALBASE}/lib --disable-mp3splttest

#PORTDOCS=	*

#OPTIONS_DEFINE=	DOCS NLS
OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

#DOXYGEN_LIB_DEPENDS=	libgvc.so:graphics/graphviz
#DOXYGEN_BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:devel/doxygen
#DOXYGEN_CONFIGURE_OFF=	--disable-doxygen-doc

.include <bsd.port.mk>
