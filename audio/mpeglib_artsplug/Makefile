# New ports collection makefile for:	mpeglib_artsplug
# Date created:				July 09 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpeglib_artsplug
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	6
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
PKGNAMEPREFIX=	kdemultimedia-
DISTNAME=	kdemultimedia-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Legacy KDE audio backend

LIB_DEPENDS=	ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

CONFLICTS=	kdemultimedia-3.1.* kdemultimedia-3.2.[0-3]

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_AUTOTOOLS=  libtool
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/kdemultimedia-${PORTVERSION}
USE_LDCONFIG=	yes

pre-configure:
	${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	${ECHO_CMD} "mpeglib mpeglib_artsplug" > ${WRKSRC}/inst-apps

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.mk>
