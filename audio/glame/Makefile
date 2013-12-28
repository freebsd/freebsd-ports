# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glame
PORTVERSION=	2.0.1
PORTREVISION=	22
CATEGORIES=	audio gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful, fast, stable, and easily extensible sound editor for GNOME

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	libmp3lame.so:${PORTSDIR}/audio/lame \
		libmad.so:${PORTSDIR}/audio/libmad \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libguile.so:${PORTSDIR}/lang/guile

USE_AUTOTOOLS=	libltdl libtool
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix libgnomeui
USE_XORG=	xbitmaps x11

INFO=		glame glame-dev

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lltdl

post-extract:
	@cd ${WRKSRC}/doc && ${RM} -f *.info*

post-patch:
	@${REINPLACE_CMD} -e 's| libltdl|| ; s|,$$LIBLTDL,|,,| ; \
		s|,$$LTDLINCL,|,,| ; s|,$$LTLIBOBJS,|,,|' ${WRKSRC}/configure

.include <bsd.port.mk>
