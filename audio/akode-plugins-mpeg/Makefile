# New ports collection makefile for:	mpeglib_artsplug
# Date created:				July 09 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	akode-plugins-${PORTNAMESUFX}
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
PKGNAMEPREFIX=	kdemultimedia-
DISTNAME=	kdemultimedia-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	MPEG audio decoder plugin for akode

EXTRA_PATCHES=	${.CURDIR}/../../multimedia/kdemultimedia3/files/patch-configure

LIB_DEPENDS=	mad:${PORTSDIR}/audio/libmad

CONFLICTS=	kdemultimedia-3.[1-3]*

PLUGIN=		mpeg_decoder
PORTNAMESUFX=	${PLUGIN:S/_sink//:S/_decoder//:S/src_//}

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/kdemultimedia-${PORTVERSION}
INSTALLS_SHLIB=	yes

pre-configure:
	@${REINPLACE_CMD} -e 's@%%SUBDIRS%%@${PLUGIN}@g' ${WRKSRC}/akode/plugins/Makefile.in

do-build:
	cd ${WRKSRC}/akode && gmake

do-install:
	cd ${WRKSRC}/akode/plugins/${PLUGIN} && gmake install

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.mk>
