# New ports collection makefile for:	BasiliskII
# Date created:				17 April 2000
# Whom:					Maxim Sobolev
#
# $FreeBSD$
#

PORTNAME=		basiliskII
PORTVERSION=		0.8.1
CATEGORIES=		emulators
MASTER_SITES=		http://download.sourceforge.net/basilisk/
DISTNAME=		BasiliskII_src_30012000

MAINTAINER=		sobomax@FreeBSD.org

LIB_DEPENDS=		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
			esd.2:${PORTSDIR}/audio/esound \
			lthread.2:${PORTSDIR}/devel/linuxthreads

WRKSRC=			${WRKDIR}/BasiliskII-0.8/src/Unix

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

GTK_CONFIG?=		${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=		${LOCALBASE}/bin/glib12-config
ESD_CONFIG?=		${LOCALBASE}/bin/esd-config

CONFIGURE_ARGS=		--disable-fbdev-dga

CONFIGURE_ENV=		GTK_CONFIG="${GTK_CONFIG}" \
			GLIB_CONFIG="${GLIB_CONFIG}" \
			ESD_CONFIG="${ESD_CONFIG}" \
			LIBS="-L${LOCALBASE}/lib"

CFLAGS+=		-D_THREAD_SAFE -I${LOCALBASE}/include/pthread/linuxthreads

MAN1=			BasiliskII.1

post-install:
			@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
