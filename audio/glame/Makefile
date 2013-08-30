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
LIB_DEPENDS=	mp3lame:${PORTSDIR}/audio/lame \
		mad:${PORTSDIR}/audio/libmad \
		vorbis:${PORTSDIR}/audio/libvorbis \
		guile:${PORTSDIR}/lang/guile

USE_AUTOTOOLS=	libltdl libtool
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
USES=		gmake pathfix gettext
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
