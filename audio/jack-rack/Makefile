# New ports collection makefile for:	jack-rack
# Date created:				30 Dec 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jack-rack
PORTVERSION=	1.4.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jack-rack

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A LADSPA effects rack for the JACK audio server

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	jack:${PORTSDIR}/audio/jack \
		lrdf:${PORTSDIR}/textproc/liblrdf
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USE_BZIP2=	yes
USE_GNOME=	libgnomeui libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--disable-ladcca

post-patch:
	@${REINPLACE_CMD} -e '/^jr_desktop_install/ s|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
