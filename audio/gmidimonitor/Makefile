# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	gmidimonitor
PORTVERSION=	3.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.gna.org/gmidimonitor/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ application that shows MIDI events

LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack \
		liblash.so:${PORTSDIR}/audio/lash

USES=		pkgconfig tar:bzip2
USE_GNOME=	gtk20 libglade2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	bin/gmidimonitor %%DATADIR%%/gmidimonitor.ui
PLIST_DIRS=	%%DATADIR%%

MAKE_JOBS_ARGS=	-j${MAKE_JOBS_NUMBER}

do-configure:
	@(cd ${WRKSRC} && ./waf configure --prefix=${PREFIX} --alsa=no)

do-build:
	@(cd ${WRKSRC} && ./waf ${MAKE_JOBS_ARGS})

do-install:
	@(cd ${WRKSRC} && ./waf --destdir=${STAGEDIR} install)

.include <bsd.port.mk>
