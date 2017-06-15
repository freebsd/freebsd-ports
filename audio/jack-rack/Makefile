# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jack-rack
PORTVERSION=	1.4.7
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	LADSPA effects rack for the JACK audio server

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LIB_DEPENDS=	libjack.so:audio/jack \
		liblrdf.so:textproc/liblrdf
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa

USE_GNOME=	libgnomeui libxml2
USES=		gettext shebangfix pkgconfig python tar:bzip2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm
CONFIGURE_ARGS=	--disable-ladcca --disable-lash --disable-aseq
SHEBANG_FILES=	ecarack

post-patch:
	@${REINPLACE_CMD} -e '/^jr_desktop_install/ s|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
