# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jack-rack
PORTVERSION=	1.4.7
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	LADSPA effects rack for the JACK audio server

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack \
		liblrdf.so:${PORTSDIR}/textproc/liblrdf
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USE_BZIP2=	yes
NO_STAGE=	yes
USE_GNOME=	libgnomeui libxml2
USES=		gettext shebangfix pkgconfig
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-ladcca --disable-lash --disable-aseq
SHEBANG_FILES=	ecarack

post-patch:
	@${REINPLACE_CMD} -e '/^jr_desktop_install/ s|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
