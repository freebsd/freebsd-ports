# New ports collection makefile for:    xine-dvdnav-plugin
# Date created:         21 Nov 2001
# Whom:                 MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	xine_dvdnav_plugin
PORTVERSION=	0.9.13
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dvd
DISTNAME=	xine-dvdnav-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org

LIB_DEPENDS=	xine.2:${PORTSDIR}/graphics/libxine \
		dvdnav.1:${PORTSDIR}/graphics/libdvdnav

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	THREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		THREAD_LIBS="${PTHREAD_LIBS}" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e \
		's|THREAD_LIBS=.*$$|THREAD_LIBS="\$$THREAD_LIBS"|g ; \
		 s|THREAD_CFLAGS=.*$$|THREAD_CFLAGS="\$$THREAD_CFLAGS"|g ; \
		 s|-L/usr/local/lib||g ; \
		 s|-I/usr/local/include||g' ${WRKSRC}/configure

.include <bsd.port.mk>
