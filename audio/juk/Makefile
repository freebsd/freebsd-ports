# New ports collection makefile for:	mpeglib_artsplug
# Date created:				July 09 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	juk
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
PKGNAMEPREFIX=	kdemultimedia-
DISTNAME=	kdemultimedia-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE audio player

LIB_DEPENDS=	akode:${PORTSDIR}/audio/akode \
		musicbrainz:${PORTSDIR}/audio/libmusicbrainz \
		tag:${PORTSDIR}/audio/taglib \
		tunepimp:${PORTSDIR}/audio/libtunepimp

CONFLICTS=	kdemultimedia-3.3*

OPTIONS=	GSTREAMER "Enable gstreamer support" off

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/kdemultimedia-${PORTVERSION}
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/lib/libgstplay-0.8.so)
.	if !defined(WITH_GSTREAMER)
GSTREAMER_OVERRIDE=yes
WITH_GSTREAMER=	yes
.	endif
.endif

.if defined(WITH_GSTREAMER)
LIB_DEPENDS+=	gstreamer:${PORTSDIR}/multimedia/gstreamer \
		gstplay:${PORTSDIR}/multimedia/gstreamer-plugins
.endif

pre-everything::
.if defined(GSTREAMER_OVERRIDE)
	@${ECHO_MSG}
	@${ECHO_MSG} "*********************************************************"
	@${ECHO_MSG} "* gstreamer is installed and support has been enabled   *"
	@${ECHO_MSG} "* automatically (no additional files will be installed) *"
	@${ECHO_MSG} "*********************************************************"
	@${ECHO_MSG}
.endif

pre-configure:
	${ECHO_CMD} "akode juk" > ${WRKSRC}/inst-apps

do-install:
	cd ${WRKSRC}/juk && gmake install

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
