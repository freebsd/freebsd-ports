# New ports collection makefile for:    libdvdnav
# Date created:         21 May 2002
# Whom:                 MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	libdvdnav
PORTVERSION=	0.1.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dvd

MAINTAINER=	nobutaka@FreeBSD.org

LIB_DEPENDS=	dvdread.2:${PORTSDIR}/multimedia/libdvdread

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	THREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		THREAD_LIBS="${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e \
		's|THREAD_LIBS=.*$$|THREAD_LIBS="\$$THREAD_LIBS"|g ; \
		 s|THREAD_CFLAGS=.*$$|THREAD_CFLAGS="\$$THREAD_CFLAGS"|g ; \
		 s|-L/usr/local/lib|-L${LOCALBASE}/lib|g ; \
		 s|-I/usr/local/include|-I${LOCALBASE}/include|g' ${WRKSRC}/configure

.include <bsd.port.mk>
