# New ports collection makefile for:	google-earth
# Date created:				Jun 13 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	google-earth
PORTVERSION=	4.3.7284.3916
CATEGORIES=	astro deskutils geography
MASTER_SITES=	http://dl.google.com/earth/client/current/
DISTFILES=	${TARGET_DISTFILE}
EXTRACT_ONLY=	# none

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Explore, Search and Discover

EXTRACT_DEPENDS=	unmakeself:${PORTSDIR}/archivers/unmakeself
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info \
		${LINUXBASE}/usr/lib/libgthread-2.0.so.0:${PORTSDIR}/devel/linux-glib2

RESTRICTED=	Not sure about redistribution rights

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\..*//g}/

USE_LINUX=	yes
USE_GNOME=	desktopfileutils

REAL_DISTFILE=		GoogleEarthLinux.bin
TARGET_DISTFILE=	GoogleEarthLinux-${PORTVERSION}.bin

FETCH_CMD=	/usr/bin/fetch -ARm
FETCH_BEFORE_ARGS=	-o ${TARGET_DISTFILE}

.include <bsd.port.pre.mk>

UNMAKESELF=	${LOCALBASE}/bin/unmakeself

.if defined(WITH_NVIDIA_GL)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri
.endif

do-fetch:
	@if [ ! -f ${DISTDIR}/${TARGET_DISTFILE} ]; then \
		cd ${DISTDIR}; \
		${FETCH_CMD} ${FETCH_BEFORE_ARGS} -1 ${MASTER_SITES:S|$|${REAL_DISTFILE}|g} ${FETCH_AFTER_ARGS}; \
	fi

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}
	@cd ${WRKSRC} && ${UNMAKESELF} ${DISTFILES} && ${RM} -f ${DISTFILES}
	@cd ${WRKSRC} && ${TAR} xf googleearth-data.tar && ${RM} -f googleearth-data.tar
	@cd ${WRKSRC} && ${TAR} xf googleearth-linux-x86.tar && ${RM} -f googleearth-linux-x86.tar

do-patch:
	@${REINPLACE_CMD} -i "" -e 's|^# Set the home.*|GOOGLEEARTH_DATA_PATH=${DATADIR}|' ${WRKSRC}/bin/googleearth
	@${REINPLACE_CMD} -i "" -e "s|^# Let's boogie.*|rm -f \$${HOME}/.googleearth/instance-running-lock|" ${WRKSRC}/bin/googleearth
	@${REINPLACE_CMD} -i "" -e 's/^TMPPATH.*/exit 0/' ${WRKSRC}/postinstall.sh
	@${REINPLACE_CMD} -i "" -e 's|\"\$$SETUP_INSTALLPATH/|\"${WRKSRC}/|' ${WRKSRC}/postinstall.sh
	@${REINPLACE_CMD} -i "" -e 's|\$$SETUP_INSTALLPATH/googleearth |${PREFIX}/bin/googleearth |' ${WRKSRC}/postinstall.sh

do-build:
	@${SETENV} SETUP_INSTALLPATH=${DATADIR} ${WRKSRC}/postinstall.sh
	@cd ${WRKSRC} && ${RM} -rf setup.* preuninstall.sh postinstall.sh
	@${CHOWN} -R ${SHAREDOWN}:${SHAREDGRP} ${WRKSRC}

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/googleearth-mimetypes.xml ${PREFIX}/share/mime/packages/
	${INSTALL_DATA} ${WRKSRC}/Google-googleearth.desktop ${PREFIX}/share/applications/googleearth.desktop
	${CP} -rp ${WRKSRC}/* ${DATADIR}
	${RM} -f ${DATADIR}/googleearth-mimetypes.xml ${DATADIR}/googleearth.desktop
	${LN} -sf ${DATADIR}/bin/googleearth ${PREFIX}/bin/
	-@update-mime-database ${PREFIX}/share/mime
	-@update-desktop-database

.include <bsd.port.post.mk>
