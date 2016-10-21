# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glame
PORTVERSION=	2.0.1
PORTREVISION=	27
CATEGORIES=	audio gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful, fast, stable, and easily extensible sound editor for GNOME

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LIB_DEPENDS=	libmp3lame.so:audio/lame \
		libmad.so:audio/libmad \
		libvorbis.so:audio/libvorbis \
		libltdl.so:devel/libltdl \
		libguile.so:lang/guile

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
USES=		gettext gmake pathfix pkgconfig libtool makeinfo
USE_GNOME=	gnomeprefix libgnomeui
USE_XORG=	xbitmaps x11
INSTALL_TARGET=	install-strip

INFO=		glame glame-dev

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lltdl

post-extract:
	@cd ${WRKSRC}/doc && ${RM} *.info*

post-patch:
	@${REINPLACE_CMD} -e 's| libltdl|| ; s|,$$LIBLTDL,|,,| ; \
		s|,$$LTDLINCL,|,,| ; s|,$$LTLIBOBJS,|,,|' ${WRKSRC}/configure

.include <bsd.port.mk>
