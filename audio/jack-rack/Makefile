# New ports collection makefile for:	jack-rack
# Date created:				30 Dec 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jack-rack
PORTVERSION=	1.4.7
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/jack-rack

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A LADSPA effects rack for the JACK audio server

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	jack:${PORTSDIR}/audio/jack \
		lrdf:${PORTSDIR}/textproc/liblrdf
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USE_BZIP2=	yes
USE_GNOME=	libgnomeui libxml2
USE_GETTEXT=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-ladcca --disable-lash

post-patch:
	@${REINPLACE_CMD} -e '/^jr_desktop_install/ s|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|' ${WRKSRC}/ecarack

.include <bsd.port.mk>
