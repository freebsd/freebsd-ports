# New ports collection makefile for:	xine_mms_plugin
# Date created:				2001/02/04
# Whom:					Norikatsu Shigemura <nork@cityfujisawa.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	xine_mms_plugin
PORTVERSION=	0.0.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.geocities.com/majormms/
DISTNAME=	${PORTNAME:S/_mms_plugin/-mms/}-${PORTVERSION}

MAINTAINER=	nork@cityfujisawa.ne.jp

LIB_DEPENDS=	xine.0:${PORTSDIR}/graphics/libxine

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	THREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		THREAD_LIBS="${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e \
		's|THREAD_LIBS=.*$$|THREAD_LIBS="\$$THREAD_LIBS"|g ; \
		 s|THREAD_CFLAGS=.*$$|THREAD_CFLAGS="\$$THREAD_CFLAGS"|g ; \
		 s|-L/usr/local/lib||g ; \
		 s|-I/usr/local/include||g' ${WRKSRC}/configure

.include <bsd.port.mk>
