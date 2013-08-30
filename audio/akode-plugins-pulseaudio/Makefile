# Created by: Scot W. Hetzel <swhetzel@gmail.com>
# $FreeBSD$

PORTNAME=	akode-plugins-${PORTNAMESUFX}
PORTVERSION=	2.0.2
PORTREVISION=	5
CATEGORIES=	audio kde
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	laszlof
DISTNAME=	30375-akode-${PORTVERSION}

MAINTAINER=	swhetzel@gmail.com
COMMENT=	Pulseaudio output plugin for akode
LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	pulse-simple:${PORTSDIR}/audio/pulseaudio

CONFLICTS=	kdemultimedia-3.[1-3]* akode-plugins-polypaudio-[0-9]*

PLUGIN=		polyp_sink
PORTNAMESUFX=	pulseaudio

USES=		gmake
USE_AUTOTOOLS=	libltdl
USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/akode-${PORTVERSION}
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libakode_polyp_sink.a lib/libakode_polyp_sink.la \
		lib/libakode_polyp_sink.so

LDFLAGS+=	-L${WRKSRC}/akode/lib/.libs
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
