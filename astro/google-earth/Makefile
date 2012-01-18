# New ports collection makefile for:	google-earth
# Date created:				Jun 13 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	google-earth
PORTVERSION=	6.1.0.5001
PORTEPOCH=	1
CATEGORIES=	astro deskutils geography
MASTER_SITES=	http://dl.google.com/earth/client/advanced/previous/:previous \
		http://dl.google.com/earth/client/current/:current
DISTFILES=	google-earth-stable_current_i386.rpm:current
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Explore, Search and Discover

EXTRACT_DEPENDS+=	${RPM2CPIO}:${PORTSDIR}/archivers/rpm
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

RPM2CPIO?=	${LOCALBASE}/bin/rpm2cpio
EXTRACT_CMD?=	${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

RESTRICTED=	Not sure about redistribution rights

WRKSRC=		${WRKDIR}
SUB_FILES=	Google-googleearth.desktop
NO_BUILD=	yes

USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
USE_GNOME=	desktopfileutils
USE_PERL5_BUILD=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_NVIDIA_GL)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
USE_LINUX_APPS+=	dri
.endif

.if ${OSVERSION}<700055
IGNORE=	FreeBSD>=7.X is needed with Linux emulation 2.6.x
.elif ${OSVERSION}<800076 && \
	(! defined (OVERRIDE_LINUX_NONBASE_PORTS) || \
	 ! (${OVERRIDE_LINUX_NONBASE_PORTS} == f10))
IGNORE=	needs non-default linux ports (define OVERRIDE_LINUX_BASE_PORT=f10 and OVERRIDE_LINUX_NONBASE_PORTS=f10)
.endif

.if ${OSVERSION} >= 900000 && ${ARCH} == "amd64"
BROKEN=	seems to crash on >= 9.x/amd64: http://www.freebsd.org/cgi/query-pr.cgi?pr=160422
.endif

post-patch:
	@${REINPLACE_CMD} -i "" -e 's|^# Set the home.*|GOOGLEEARTH_DATA_PATH=${DATADIR}|' ${WRKSRC}/opt/google/earth/free/googleearth
	@${REINPLACE_CMD} -i "" -e "s|^# Let's boogie.*|rm -f \$${HOME}/.googleearth/instance-running-lock|" ${WRKSRC}/opt/google/earth/free/googleearth
	@${RM} ${WRKSRC}/opt/google/earth/free/googleearth.orig
	@${RM} ${WRKSRC}/opt/google/earth/free/google-earth
	${PERL} -i -pe 's|/lib/ld-lsb.so.3\0\0\0|/lib/ld-linux.so.2\0|' ${WRKSRC}/opt/google/earth/free/googleearth-bin

pre-su-install:
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/googleearth-mimetypes.xml ${PREFIX}/share/mime/packages/
	${INSTALL_DATA} ${WRKSRC}/Google-googleearth.desktop ${PREFIX}/share/applications/googleearth.desktop
	${CP} -rp ${WRKSRC}/opt/google/earth/free/* ${DATADIR}
	${RM} -f ${DATADIR}/googleearth-mimetypes.xml ${DATADIR}/googleearth.desktop
	${INSTALL_SCRIPT} ${FILESDIR}/browserwrapper ${DATADIR}
	${LN} -sf ${DATADIR}/googleearth ${PREFIX}/bin/
	-@update-mime-database ${PREFIX}/share/mime
	-@update-desktop-database

.include <bsd.port.post.mk>
