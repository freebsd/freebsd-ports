# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	akode
PORTVERSION=	2.0.2
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	audio kde
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	laszlof
PKGNAMESUFFIX=	-plugins-${PORTNAMESUFX}
DISTNAME=       30375-akode-${PORTVERSION}

MAINTAINER=	swhetzel@gmail.com
COMMENT=	FFMPEG decoder plugin for akode
LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	avcodec:${PORTSDIR}/multimedia/ffmpeg

CONFLICTS=	kdemultimedia-3.[1-3]*

PLUGIN=		ffmpeg_decoder
PORTNAMESUFX=	${PLUGIN:S/_sink//:S/_decoder//:S/src_//}

USES=		gmake
USE_AUTOTOOLS=	libltdl
USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/akode-${PORTVERSION}
USE_LDCONFIG=	yes

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
