# New ports collection Makefile for: 	swhplugins
# Date created:			12 May 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=		swhplugins
PORTVERSION=		0.3.6
CATEGORIES=		audio
MASTER_SITES=		http://plugin.org.uk/releases/${PORTVERSION}/
DISTNAME=		swh-plugins-${PORTVERSION}

MAINTAINER=		ports@FreeBSD.org

BUILD_DEPENDS=		${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=		fftw.2:${PORTSDIR}/math/fftw

GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes
USE_REINPLACE=		yes
USE_GMAKE=		yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

post-patch:
		${REINPLACE_CMD} -e "s,-O6,," ${WRKSRC}/configure

.include <bsd.port.mk>
