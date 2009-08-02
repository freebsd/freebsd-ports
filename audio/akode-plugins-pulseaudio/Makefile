# New ports collection makefile for:	akode-plugins-pulseaudio
# Date created:				March 03 2008
# Whom:					Scot W. Hetzel <swhetzel@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	akode-plugins-${PORTNAMESUFX}
PORTVERSION=	2.0.2
PORTREVISION=	2
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=distfiles
DISTNAME=	30375-akode-${PORTVERSION}.tar.bz2
EXTRACT_SUFX=	# none

MAINTAINER=	swhetzel@gmail.com
COMMENT=	Pulseaudio output plugin for akode

LIB_DEPENDS=	pulse-simple:${PORTSDIR}/audio/pulseaudio

CONFLICTS=	kdemultimedia-3.[1-3]* akode-plugins-polypaudio-[0-9]*

PLUGIN=		polyp_sink
PORTNAMESUFX=	pulseaudio

USE_AUTOTOOLS=	libltdl
USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/akode-${PORTVERSION}
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libakode_polyp_sink.a lib/libakode_polyp_sink.la \
		lib/libakode_polyp_sink.so

CONFIGURE_ENV+=	LDFLAGS=-L${WRKSRC}/akode/lib/.libs
CONFIGURE_ARGS+=--with-extra-libs=${LOCALBASE}/lib \
		--with-extra-includes=${LOCALBASE}/include

post-patch:
	@${SETENV} TZ=UTC \
	${TOUCH} -t 200607222217.01 ${WRKSRC}/akode/lib/akode_export.h.in

pre-configure:
	@${REINPLACE_CMD} -e 's@%%SUBDIRS%%@${PLUGIN}@g' ${WRKSRC}/akode/plugins/Makefile.in

do-build:
	cd ${WRKSRC}/akode && ${GMAKE}

do-install:
	cd ${WRKSRC}/akode/plugins/${PLUGIN} && ${GMAKE} install

.include <bsd.port.mk>
