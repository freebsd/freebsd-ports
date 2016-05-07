# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	gnomoradio
PORTVERSION=	0.15.1
PORTREVISION=	19
CATEGORIES=	audio net
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for finding and playing free music from the Internet

LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libao.so:audio/libao

USES=		pathfix pkgconfig libtool
GNU_CONFIGURE=	yes
USE_GNOME=	gconfmm26 gnomeprefix gtkmm24
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} '/^rainbow_get_LDADD =/s/$$/ $$(RAINBOW_LIBS)/' \
		${WRKSRC}/rainbow/Makefile.in
	@${REINPLACE_CMD} -e 's|CCLD = $$(CC)|CCLD = $$(CXX)|' \
		${WRKSRC}/roboradio/mp3/Makefile.in
	@${REINPLACE_CMD} -e 's|static char|static const char|' \
		${WRKSRC}/gnomoradio/*.xpm
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/roboradio/mp3/common.c \
		${WRKSRC}/roboradio/mp3/esd-audio.[ch] \
		${WRKSRC}/roboradio/mp3/id3.h

.include <bsd.port.mk>
