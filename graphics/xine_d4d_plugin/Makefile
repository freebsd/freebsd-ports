# New ports collection makefile for:    xine_d4d_plugin
# Date created:         28 Aug 2001
# Whom:                 HIYAMA Takeshi <gibbon@cocoa.freemail.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	xine_d4d_plugin
PORTVERSION=	0.3.2
CATEGORIES=	graphics
MASTER_SITES=	http://debianlinux.net/ \
		http://hermes.homelinux.net/xine/

MAINTAINER=	gibbon@cocoa.freemail.ne.jp

LIB_DEPENDS=	xine.2:${PORTSDIR}/graphics/libxine

GNU_CONFIGURE=	yes
USE_X_PREFIX=		yes
CONFIGURE_ENV=	THREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		THREAD_LIBS="${PTHREAD_LIBS}"
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
