# New ports collection makefile for:	gimp-gap
# Date created:		2007-08-22
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gimp-gap
PORTVERSION=	2.2.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		http://gimp.mirrors.hoobly.com/%SUBDIR%/ \
		http://ftp.gwdg.de/pub/misc/grafik/gimp/%SUBDIR%/ \
		ftp://ftp.fh-heilbronn.de/mirrors/ftp.gimp.org/%SUBDIR%/ \
		ftp://ftp.insync.net/pub/mirrors/ftp.gimp.org/%SUBDIR%/ \
		http://www.mirrorservice.org/sites/ftp.gimp.org/pub/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gimp/plug-ins/v${PORTVERSION:R}/gap

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	GIMP Animation Package

BUILD_DEPENDS=	wavplay:${PORTSDIR}/audio/wavplay
LIB_DEPENDS=	xvidcore.4:${PORTSDIR}/multimedia/xvid \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		gimp-2.0:${PORTSDIR}/graphics/gimp-app
RUN_DEPENDS=	wavplay:${PORTSDIR}/audio/wavplay

USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-libmpeg3
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/ffmpeg" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.mk>
