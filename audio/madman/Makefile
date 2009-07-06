# New ports collection makefile for:	madman
# Date created:		2005-10-12
# Whom:			Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	madman
PORTVERSION=	0.93
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	madman

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An advanced digital music manager

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons
LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		id3tag.0:${PORTSDIR}/audio/libid3tag \
		vorbis.4:${PORTSDIR}/audio/libvorbis
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

USE_QT_VER=	3
USE_GNOME=	glib12

PLIST_FILES=	bin/madman \
		lib/madman/plugins/burn_to_audio_cd \
		lib/madman/plugins/burn_to_data_cd \
		lib/madman/plugins/export_m3u \
		lib/madman/plugins/move_to_trash
PLIST_DIRS=	lib/madman/plugins lib/madman

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/scons -C ${WRKSRC} prefix=${PREFIX} \
	qt_directory=${QT_PREFIX} add_c_include_dirs=${LOCALBASE}/include add_lib_dirs=${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/madman ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/madman
	${MKDIR} ${PREFIX}/lib/madman/plugins
	for plugin in burn_to_audio_cd burn_to_data_cd export_m3u move_to_trash; do \
		${INSTALL_DATA} -m0755 ${WRKSRC}/plugins/$$plugin ${PREFIX}/lib/madman/plugins; \
	done

.include <bsd.port.mk>
