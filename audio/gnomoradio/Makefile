# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=		gnomoradio
PORTVERSION=		0.15.1
PORTREVISION=	18
CATEGORIES=		audio net
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		gahr@FreeBSD.org
COMMENT=		Program for finding and playing free music from the Internet

LIB_DEPENDS=		libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20 \
			libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24 \
			libgconfmm-2.6.so:${PORTSDIR}/devel/gconfmm26 \
			libxml++-2.6.so:${PORTSDIR}/textproc/libxml++26 \
			libvorbis.so:${PORTSDIR}/audio/libvorbis \
			libao.so:${PORTSDIR}/audio/libao

USES=			pathfix pkgconfig libtool
GNU_CONFIGURE=		yes
USE_GNOME=		gnomeprefix
USE_LDCONFIG=		yes
LIBTOOLFLAGS=		--tag=CXX
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="`pkg-config --libs glibmm-2.4`"

post-patch:
	@${REINPLACE_CMD} -e 's|CCLD = $$(CC)|CCLD = $$(CXX)|' \
		${WRKSRC}/roboradio/mp3/Makefile.in
	@${REINPLACE_CMD} -e 's|static char|static const char|' \
		${WRKSRC}/gnomoradio/*.xpm
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/roboradio/mp3/common.c \
		${WRKSRC}/roboradio/mp3/esd-audio.[ch] \
		${WRKSRC}/roboradio/mp3/id3.h

.include <bsd.port.mk>
