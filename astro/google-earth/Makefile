# $FreeBSD$

PORTNAME=	google-earth
PORTVERSION=	7.1.5.1557
PORTREVISION=	1
PORTEPOCH=	3
CATEGORIES=	astro deskutils geography
MASTER_SITES=	http://dl.google.com/earth/client/advanced/previous/:previous \
		http://dl.google.com/earth/client/current/:current
DISTFILES=	GoogleEarthLinux.bin:current
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual globe, map and geographical information program

RESTRICTED=	Not really sure about the redistribution terms

OPTIONS_DEFAULT=	LINUX_DRI
OPTIONS_SINGLE=		LIBGL
OPTIONS_SINGLE_LIBGL=	LINUX_DRI NVIDIA_GL NVIDIA_GL_340 NVIDIA_GL_304
LINUX_DRI_DESC=		libGL support via Linux DRI libraries
NVIDIA_GL_DESC=		libGL support via nvidia-driver
NVIDIA_GL_340_DESC=	libGL support via nvidia-driver-340
NVIDIA_GL_304_DESC=	libGL support via nvidia-driver-304

USES=		desktop-file-utils linux makeself perl5 shared-mime-info
USE_LINUX=	xorglibs curl nss
USE_PERL5=	patch build
NO_WRKSUBDIR=	yes

NVIDIA_GL_RUN_DEPENDS=		${LINUXBASE}/usr/lib/libGL.so.1:x11/nvidia-driver
NVIDIA_GL_340_RUN_DEPENDS=	${LINUXBASE}/usr/lib/libGL.so.1:x11/nvidia-driver-340
NVIDIA_GL_304_RUN_DEPENDS=	${LINUXBASE}/usr/lib/libGL.so.1:x11/nvidia-driver-304
LINUX_DRI_USE=			LINUX=dri,libpciaccess

post-extract:
	@cd ${WRKSRC} && ${TAR} -xf googleearth-data.tar && ${RM} googleearth-data.tar
	@cd ${WRKSRC} && ${TAR} -xf googleearth-linux-x86.tar && ${RM} googleearth-linux-x86.tar

post-patch:
	@${REINPLACE_CMD} -i "" -e '/OS.*=/s|linux|FreeBSD|' ${WRKSRC}/drivers.ini
	@${REINPLACE_CMD} -i "" -e 's|^# Set the home.*|GOOGLEEARTH_DATA_PATH=${DATADIR}|' ${WRKSRC}/bin/googleearth
	@${REINPLACE_CMD} -i "" -e "s|^# Let's boogie.*|rm -f ${LINUXBASE}\$${HOME}/.googleearth/instance-running-lock|" ${WRKSRC}/bin/googleearth
	@${REINPLACE_CMD} -i "" -e 's/^TMPPATH.*/exit 0/' ${WRKSRC}/postinstall.sh
	@${REINPLACE_CMD} -i "" -e 's|\"\$$SETUP_INSTALLPATH/|\"${WRKSRC}/|' ${WRKSRC}/postinstall.sh
	@${REINPLACE_CMD} -i "" -e 's|\$$SETUP_INSTALLPATH/googleearth |${PREFIX}/bin/googleearth |' ${WRKSRC}/postinstall.sh
	${RM} ${WRKSRC}/libcurl.so.4
	${PERL} -i -pe 's|/lib/ld-lsb.so.3\0\0\0|/lib/ld-linux.so.2\0|' ${WRKSRC}/googleearth-bin
post-patch-LINUX_DRI-off:
	@${REINPLACE_CMD} 's|%%LIBGL_ALWAYS_SOFTWARE%%||' ${WRKSRC}/bin/googleearth
post-patch-LINUX_DRI-on:
	@${REINPLACE_CMD} 's|%%LIBGL_ALWAYS_SOFTWARE%%|LIBGL_ALWAYS_SOFTWARE=yes|' ${WRKSRC}/bin/googleearth

do-build:
	@${SETENV} SETUP_INSTALLPATH=${DATADIR} ${WRKSRC}/postinstall.sh
	@cd ${WRKSRC} && ${RM} -r setup.* preuninstall.sh postinstall.sh \
		bin/googleearth.orig

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/googleearth-mimetypes.xml \
		${STAGEDIR}${PREFIX}/share/mime/packages/
	${INSTALL_DATA} ${WRKSRC}/Google-googleearth.desktop \
		${STAGEDIR}${PREFIX}/share/applications/googleearth.desktop
	${INSTALL_SCRIPT} ${WRKSRC}/bin/googleearth ${STAGEDIR}${DATADIR}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/googleearth-bin ${STAGEDIR}${DATADIR}/
	${RM} ${WRKSRC}/googleearth-mimetypes.xml \
		${WRKSRC}/googleearth.desktop \
		${WRKSRC}/googleearth-bin \
		${WRKSRC}/bin/googleearth
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${FILESDIR}/browserwrapper \
		${STAGEDIR}${DATADIR}/bin/
	${LN} -sf ../${DATADIR_REL}/bin/googleearth \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
