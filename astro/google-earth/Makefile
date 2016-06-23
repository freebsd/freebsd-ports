# $FreeBSD$

PORTNAME=	google-earth
PORTVERSION=	6.0.3.2197
PORTREVISION=	4
PORTEPOCH=	3
CATEGORIES=	astro deskutils geography
MASTER_SITES=	http://dl.google.com/earth/client/advanced/previous/:previous \
		http://dl.google.com/earth/client/current/:current
DISTFILES=	GoogleEarthLinux.bin:current
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Explore, Search, and Discover

EXTRACT_DEPENDS=	unmakeself:archivers/unmakeself

RESTRICTED=	Not really sure about the redistribution terms

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\..*//g}/

OPTIONS_DEFINE=	NVIDIA

USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs curl nss
USES=		perl5 shared-mime-info desktop-file-utils
USE_PERL5=	patch build

#SUB_FILES=	bin/googleearth

UNMAKESELF=	${LOCALBASE}/bin/unmakeself

NVIDIA_RUN_DEPENDS=	${LINUXBASE}/usr/lib/libGL.so.1:x11/nvidia-driver
NVIDIA_USE_OFF=	LINUX_APPS=dri,libpciaccess

# Fixed by the first post-patch target line?  Also, linprocfs needs to be mounted.
#BROKEN=	seems to crash on >= 9.x/amd64: http://www.freebsd.org/cgi/query-pr.cgi?pr=160422

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${_DISTFILES} ${WRKSRC}
	@cd ${WRKSRC} && ${UNMAKESELF} ${_DISTFILES} && ${RM} -f ${_DISTFILES}
	@cd ${WRKSRC} && ${TAR} xf googleearth-data.tar && ${RM} -f googleearth-data.tar
	@cd ${WRKSRC} && ${TAR} xf googleearth-linux-x86.tar && ${RM} -f googleearth-linux-x86.tar

post-patch:
	@${REINPLACE_CMD} -e '/OS.*=/s|linux|FreeBSD|' ${WRKSRC}/drivers.ini
	@${REINPLACE_CMD} -e 's|^# Set the home.*|GOOGLEEARTH_DATA_PATH=${DATADIR}|' ${WRKSRC}/bin/googleearth
	@${REINPLACE_CMD} -i "" -e "s|^# Let's boogie.*|rm -f ${LINUXBASE}\$${HOME}/.googleearth/instance-running-lock|" ${WRKSRC}/bin/googleearth
	@${REINPLACE_CMD} -i "" -e 's/^TMPPATH.*/exit 0/' ${WRKSRC}/postinstall.sh
	@${REINPLACE_CMD} -i "" -e 's|\"\$$SETUP_INSTALLPATH/|\"${WRKSRC}/|' ${WRKSRC}/postinstall.sh
	@${REINPLACE_CMD} -i "" -e 's|\$$SETUP_INSTALLPATH/googleearth |${PREFIX}/bin/googleearth |' ${WRKSRC}/postinstall.sh
	${RM} ${WRKSRC}/libcurl.so.4
	${PERL} -i -pe 's|/lib/ld-lsb.so.3\0\0\0|/lib/ld-linux.so.2\0|' ${WRKSRC}/googleearth-bin
post-patch-NVIDIA-on:
	@${REINPLACE_CMD} 's|%%LIBGL_ALWAYS_SOFTWARE%%||' ${WRKSRC}/bin/googleearth
post-patch-NVIDIA-off:
	@${REINPLACE_CMD} 's|%%LIBGL_ALWAYS_SOFTWARE%%|LIBGL_ALWAYS_SOFTWARE=yes|' ${WRKSRC}/bin/googleearth

do-build:
	@${SETENV} SETUP_INSTALLPATH=${DATADIR} ${WRKSRC}/postinstall.sh
	@cd ${WRKSRC} && ${RM} -rf setup.* preuninstall.sh postinstall.sh \
		bin/googleearth.orig

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/googleearth-mimetypes.xml \
		${STAGEDIR}${PREFIX}/share/mime/packages/
	${INSTALL_DATA} ${WRKSRC}/Google-googleearth.desktop \
		${STAGEDIR}${PREFIX}/share/applications/googleearth.desktop
	${CP} -rp ${WRKSRC}/* ${STAGEDIR}${DATADIR}
	${RM} -f ${STAGEDIR}${DATADIR}/googleearth-mimetypes.xml \
		${STAGEDIR}${DATADIR}/googleearth.desktop
	${INSTALL_SCRIPT} ${FILESDIR}/browserwrapper \
		${STAGEDIR}${DATADIR}/bin/
	${LN} -sf ../${DATADIR_REL}/bin/googleearth \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
