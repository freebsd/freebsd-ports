# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=		gnomoradio
PORTVERSION=		0.15.1
PORTREVISION=		16
CATEGORIES=		audio net
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		gahr@FreeBSD.org
COMMENT=		A program for finding and playing free music from the Internet

LIB_DEPENDS=		libssigc-2.0.so:${PORTSDIR}/devel/libsigc++20 \
			libsgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24 \
			libsgconfmm-2.6.so:${PORTSDIR}/devel/gconfmm26 \
			libsxml\\+\\+-2.6.so:${PORTSDIR}/textproc/libxml++26 \
			libsvorbis.so:${PORTSDIR}/audio/libvorbis \
			libsao.so:${PORTSDIR}/audio/libao

USES=			pathfix pkgconfig
NO_STAGE=	yes
USE_GNOME=		gnomeprefix
USE_AUTOTOOLS=		libtool
USE_LDCONFIG=		yes
LIBTOOLFLAGS=		--tag=CXX
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|CCLD = $$(CC)|CCLD = $$(CXX)|; \
		s|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/roboradio/mp3/Makefile.in
	@${REINPLACE_CMD} -e 's|static char|static const char|' \
		${WRKSRC}/gnomoradio/*.xpm
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/roboradio/mp3/common.c \
		${WRKSRC}/roboradio/mp3/esd-audio.[ch] \
		${WRKSRC}/roboradio/mp3/id3.h

.include <bsd.port.mk>
