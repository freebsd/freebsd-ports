# Created by: lewiz <purple@lewiz.net>
# $FreeBSD$
#   $MCom: ports/accessibility/dasher/Makefile,v 1.66 2009/03/18 04:59:21 marcus Exp $

PORTNAME=	dasher
PORTVERSION=	4.10.1
PORTREVISION=	8
PORTEPOCH=	2
CATEGORIES=	accessibility editors x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	lewiz@compsoc.man.ac.uk
COMMENT=	Information efficient text-entry interface

BUILD_DEPENDS=	rarian-sk-config:textproc/rarian
LIB_DEPENDS=	libogg.so:audio/libogg
RUN_DEPENDS=	rarian-sk-config:textproc/rarian

USES=		gettext gmake pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack libgnomeui atspi \
		libwnck gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	dasher.schemas

CONFIGURE_ARGS+=	--disable-speech

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-O2||g'
	@${REINPLACE_CMD} -e 's|__gnu_cxx::lldiv|lldiv|' \
		${WRKSRC}/Src/DasherCore/DasherViewSquare.cpp

.include <bsd.port.mk>
