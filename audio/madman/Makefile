# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	madman
PORTVERSION=	0.93
PORTREVISION=	11
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced digital music manager

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons
LIB_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms \
		id3tag:${PORTSDIR}/audio/libid3tag \
		vorbis:${PORTSDIR}/audio/libvorbis

DEPRECATED=	Depends on Qt3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_QT_VER=	3
USE_GNOME=	glib12
USE_PYTHON_RUN=	yes

PLIST_FILES=	bin/madman \
		lib/madman/plugins/burn_to_audio_cd \
		lib/madman/plugins/burn_to_data_cd \
		lib/madman/plugins/export_m3u \
		lib/madman/plugins/move_to_trash
PLIST_DIRS=	lib/madman/plugins lib/madman

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/scons \
		-C ${WRKSRC} prefix=${PREFIX} qt_directory=${QT_PREFIX} \
		add_c_include_dirs=${LOCALBASE}/include \
		add_lib_dirs=${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/madman ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/madman/plugins
.for plugin in burn_to_audio_cd burn_to_data_cd export_m3u move_to_trash
	${INSTALL_DATA} -m0755 ${WRKSRC}/plugins/${plugin} \
		${PREFIX}/lib/madman/plugins
.endfor

.include <bsd.port.mk>
