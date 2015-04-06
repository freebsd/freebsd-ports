# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	mp3splt-gtk
PORTVERSION=	0.9.2
CATEGORIES=	audio
MASTER_SITES=	SF/mp3splt/${PORTNAME}/${PORTVERSION}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Utility to split mp3 and ogg files (via GTK Interface)

LICENSE=	GPLv2

LIB_DEPENDS=	libmp3splt.so:${PORTSDIR}/audio/libmp3splt \
		libmad.so:${PORTSDIR}/audio/libmad \
		libogg.so:${PORTSDIR}/audio/libogg \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libid3tag.so:${PORTSDIR}/audio/libid3tag \
		libltdl.so:${PORTSDIR}/devel/libltdl

INSTALLS_OMF=	yes
USE_GSTREAMER1=	yes
USE_GNOME=	gnomedocutils gtk30
GNU_CONFIGURE=	yes
USES=		desktop-file-utils gmake pkgconfig

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

#DOCS_LIB_DEPENDS=	libgvc.so:${PORTSDIR}/graphics/graphviz
#DOCS_BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
#DOCS_CONFIGURE_OFF=	--disable-doxygen-doc

.include <bsd.port.mk>
