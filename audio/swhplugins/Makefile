# New ports collection Makefile for: 	swhplugins
# Date created:			12 May 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	swhplugins
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://plugin.org.uk/releases/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTNAME=	swh-plugins-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Steve Harris' huge Collection of LADSPA Plugins

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old \
		fftw.2:${PORTSDIR}/math/fftw

# includes assember code
ONLY_FOR_ARCHS=	i386

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g ; \
		 s|INCLUDED_LIBINTL=yes|INCLUDED_LIBINTL=no|g ; \
		 s|\\\$${top_builddir}/intl/libintl.a|-lintl|g ' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|#include <bits/nan.h>||g' \
		${WRKSRC}/gverb/gverb-test.c

.include <bsd.port.mk>
