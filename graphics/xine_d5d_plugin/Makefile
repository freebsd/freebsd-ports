# New ports collection makefile for:    xine_d5d_plugin
# Date created:         24 Jan 2002
# Whom:                 MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	xine_d5d_plugin
PORTVERSION=	0.2.7
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://debianlinux.net/ \
		http://hermes.homelinux.net/xine/
DISTNAME=	xine-d5d-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nobutaka@FreeBSD.org

LIB_DEPENDS=	xine.2:${PORTSDIR}/graphics/libxine \
		dvdread.2:${PORTSDIR}/multimedia/libdvdread

USE_AUTOMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	THREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		THREAD_LIBS="${PTHREAD_LIBS}"
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e \
		's|THREAD_LIBS=.*$$|THREAD_LIBS="\$$THREAD_LIBS"|g ; \
		 s|THREAD_CFLAGS=.*$$|THREAD_CFLAGS="\$$THREAD_CFLAGS"|g ; \
		 s|-L/usr/local/lib||g ; \
		 s|-I/usr/local/include||g' ${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
