# $FreeBSD$

PORTNAME=	google-earth
PORTVERSION=	6.0.3.2197
PORTEPOCH=	3
CATEGORIES=	astro deskutils geography
MASTER_SITES=	http://dl.google.com/earth/client/advanced/previous/:previous \
		http://dl.google.com/earth/client/current/:current
DISTFILES=	GoogleEarthLinux.bin:current
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	# none

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Explore, Search, and Discover

EXTRACT_DEPENDS=	unmakeself:${PORTSDIR}/archivers/unmakeself
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

RESTRICTED=	Not sure about redistribution rights

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\..*//g}/

USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
USE_GNOME=	desktopfileutils
USES=		perl5
USE_PERL5=	patch build

.include <bsd.port.pre.mk>

UNMAKESELF=	${LOCALBASE}/bin/unmakeself

.if defined(WITH_NVIDIA_GL)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
USE_LINUX_APPS+=	dri
.endif

# Fixed by the first post-patch target line?  Also, linprocfs needs to be mounted.
#.if ${OSVERSION} >= 900000 && ${ARCH} == "amd64"
#BROKEN=	seems to crash on >= 9.x/amd64: http://www.freebsd.org/cgi/query-pr.cgi?pr=160422
#.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${_DISTFILES} ${WRKSRC}
	@cd ${WRKSRC} && ${UNMAKESELF} ${_DISTFILES} && ${RM} -f ${_DISTFILES}
	@cd ${WRKSRC} && ${TAR} xf googleearth-data.tar && ${RM} -f googleearth-data.tar
	@cd ${WRKSRC} && ${TAR} xf googleearth-linux-x86.tar && ${RM} -f googleearth-linux-x86.tar

post-patch:
	@${REINPLACE_CMD} -i "" -e '/OS.*=/s|linux|FreeBSD|' ${WRKSRC}/drivers.ini
	@${REINPLACE_CMD} -i "" -e 's|^# Set the home.*|GOOGLEEARTH_DATA_PATH=${DATADIR}|' ${WRKSRC}/bin/googleearth
	@${REINPLACE_CMD} -i "" -e "s|^# Let's boogie.*|rm -f \$${HOME}/.googleearth/instance-running-lock|" ${WRKSRC}/bin/googleearth
	@${REINPLACE_CMD} -i "" -e 's/^TMPPATH.*/exit 0/' ${WRKSRC}/postinstall.sh
	@${REINPLACE_CMD} -i "" -e 's|\"\$$SETUP_INSTALLPATH/|\"${WRKSRC}/|' ${WRKSRC}/postinstall.sh
	@${REINPLACE_CMD} -i "" -e 's|\$$SETUP_INSTALLPATH/googleearth |${PREFIX}/bin/googleearth |' ${WRKSRC}/postinstall.sh
	${PERL} -i -pe 's|/lib/ld-lsb.so.3\0\0\0|/lib/ld-linux.so.2\0|' ${WRKSRC}/googleearth-bin

do-build:
	@${SETENV} SETUP_INSTALLPATH=${DATADIR} ${WRKSRC}/postinstall.sh
	@cd ${WRKSRC} && ${RM} -rf setup.* preuninstall.sh postinstall.sh \
		bin/googleearth.orig

pre-su-install:
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/googleearth-mimetypes.xml ${PREFIX}/share/mime/packages/
	${INSTALL_DATA} ${WRKSRC}/Google-googleearth.desktop ${PREFIX}/share/applications/googleearth.desktop
	${CP} -rp ${WRKSRC}/* ${DATADIR}
	${RM} -f ${DATADIR}/googleearth-mimetypes.xml ${DATADIR}/googleearth.desktop
	${INSTALL_SCRIPT} ${FILESDIR}/browserwrapper ${DATADIR}/bin
	${LN} -sf ${DATADIR}/bin/googleearth ${PREFIX}/bin/
	-@update-mime-database ${PREFIX}/share/mime
	-@update-desktop-database

.include <bsd.port.post.mk>
