# New ports collection makefile for:	mpeglib_artsplug
# Date created:				July 09 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	juk
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	2
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
		tunepimp-0.4.3:${PORTSDIR}/audio/libtunepimp-old

CONFLICTS=	kdemultimedia-3.3*

OPTIONS=	GSTREAMER "Enable gstreamer support" off

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/kdemultimedia-${PORTVERSION}
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS+=CFLAGS=-I${LOCALBASE}/include/tunepimp-0.4 \
		LDFLAGS=-L${LOCALBASE}/lib/tunepimp-0.4

WANT_GSTREAMER=	yes

.include <bsd.port.pre.mk>

.if  defined(WITH_GSTREAMER) || exists(${LOCALBASE}/lib/libgstreamer-0.10.so)
GSTREAMER_OVERRIDE=yes
USE_GSTREAMER=	yes
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

post-patch:
	@${REINPLACE_CMD} -e 's|LIBS="-ltunepimp  $$LIBS"|LIBS="-ltunepimp -liconv $$LIBS"|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-ltunepimp|-ltunepimp-0.4|g' \
			-e 's|<tunepimp/tp_c.h>|<tunepimp-0.4/tunepimp/tp_c.h>|g' \
		${WRKSRC}/configure ${WRKSRC}/juk/ktrm.cpp ${WRKSRC}/juk/Makefile.in

do-build:
	cd ${WRKSRC}/arts/runtime && ${SETENV} ${MAKE_ENV} ${GMAKE}
	cd ${WRKSRC}/juk && ${SETENV} ${MAKE_ENV} ${GMAKE}

do-install:
	cd ${WRKSRC}/juk && ${SETENV} ${MAKE_ENV} ${GMAKE} install

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
