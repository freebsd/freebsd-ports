# New ports collection makefile for:    xine_d5d_plugin
# Date created:         24 Jan 2002
# Whom:                 MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	xine_d5d_plugin
PORTVERSION=	0.1.1
CATEGORIES=	graphics
MASTER_SITES=	http://worldzone.net/technology/captaincss/ \
		http://debianlinux.net/
DISTNAME=	d5d011
EXTRACT_SUFX=	.txt

MAINTAINER=	nobutaka@FreeBSD.org

LIB_DEPENDS=	xine.0:${PORTSDIR}/graphics/libxine \
		dvdread.2:${PORTSDIR}/graphics/libdvdread

USE_AUTOMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	THREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		THREAD_LIBS="${PTHREAD_LIBS}"
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes

WRKSRC=		${WRKDIR}/xine-d5d-${PORTVERSION}

do-extract:
	(${MKDIR} ${WRKDIR}; \
	 cd ${WRKDIR}; \
	 ${SH} ${DISTDIR}/${DISTFILES}; \
	 ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} xine-d5d-${PORTVERSION}.tar.gz ${EXTRACT_AFTER_ARGS})

post-patch:
	@${PERL} -pi -e \
		's|THREAD_LIBS=.*$$|THREAD_LIBS="\$$THREAD_LIBS"|g ; \
		 s|THREAD_CFLAGS=.*$$|THREAD_CFLAGS="\$$THREAD_CFLAGS"|g ; \
		 s|-L/usr/local/lib||g ; \
		 s|-I/usr/local/include||g' ${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
