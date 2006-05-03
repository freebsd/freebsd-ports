# New ports collection makefile for:	mpeglib_artsplug
# Date created:				July 09 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	akode-plugins-${PORTNAMESUFX}
PORTVERSION=	2.0
PORTEPOCH=	1
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.kde-apps.org/content/
MASTER_SITE_SUBDIR=lofi
DISTNAME=	'download.php?content=30375'
EXTRACT_SUFX=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	OSS output plugin for akode

CONFLICTS=	kdemultimedia-3.[1-3]*

FETCH_CMD=	/usr/bin/fetch

PLUGIN=		oss_sink
PORTNAMESUFX=	${PLUGIN:S/_sink//:S/_decoder//:S/src_//}

USE_AUTOTOOLS=	libltdl
USE_AUTOTOOLS=  libtool:15
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/akode-2.0
INSTALLS_SHLIB=	yes

CONFIGURE_ENV+=	LDFLAGS=-L${WRKSRC}/akode/lib/.libs
CONFIGURE_ARGS+=--with-extra-libs=${LOCALBASE}/lib \
		--with-extra-includes=${LOCALBASE}/include

post-patch:
	@${SETENV} TZ=UTC \
	${TOUCH} -t 200511231529.06 ${WRKSRC}/akode/lib/akode_export.h.in

pre-configure:
	@${REINPLACE_CMD} -e 's@%%SUBDIRS%%@${PLUGIN}@g' ${WRKSRC}/akode/plugins/Makefile.in

do-build:
	cd ${WRKSRC}/akode && ${GMAKE}

do-install:
	cd ${WRKSRC}/akode/plugins/${PLUGIN} && ${GMAKE} install

.include <bsd.port.mk>
