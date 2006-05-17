# New ports collection makefile for:	linux-x-plane
# Date created:				25 Nov 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linux-x-plane
PORTVERSION=	8.32
CATEGORIES=	games linux
MASTER_SITES=	# empty

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A commercial flight simulator

RUN_DEPENDS=	${LINUXBASE}/lib/libgcc/libgcc_s.so.1:${PORTSDIR}/lang/linux-libgcc \
		${LINUXBASE}/usr/lib/libopenal.so.1:${PORTSDIR}/audio/linux-openal \
		${LINUXBASE}/usr/X11R6/lib/libGLU.so.1.3:${PORTSDIR}/graphics/linux_dri

IGNOREFILES=	${DISTFILES}	# user-created distribution
NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_LINUX=	yes
NO_BUILD=	yes
RESTRICTED=	"Redistribution prohibited"
NO_PACKAGE=	"Package will be 482 MB, set FORCE_PACKAGE if you really want to build it"
ONLY_FOR_ARCHS=	i386 amd64

XDIR=		${PREFIX}/lib/x-plane
XDIR_REL=	${XDIR:S,^${PREFIX}/,,}

PROGRAMS=	Airfoil-Maker Briefer Plane-Maker World-Maker X-Plane

PLIST=		${WRKDIR}/.plist
PLIST_FILES=	${PROGRAMS:S|^|bin/|} libexec/x-plane-wrapper
PLIST_DIRS=	${XDIR_REL}

SUB_FILES=	x-plane-wrapper
SUB_LIST=	XDIR="${XDIR}" PORTVERSION="${PORTVERSION}" PROGRAMS="${PROGRAMS}"

DESKTOP_ENTRIES="X-Plane Airfoil Maker" \
		"Edit X-Plane airfoils" \
		"" \
		"Airfoil-Maker" \
		"Application;Game;" \
		false \
		\
		"X-Plane Briefer" \
		"Obtain a weather briefing for your flight" \
		"" \
		"Briefer" \
		"Application;Game;" \
		false \
		\
		"X-Plane Plane Maker" \
		"Edit X-Plane planes" \
		"" \
		"Plane-Maker" \
		"Application;Game;" \
		false \
		\
		"X-Plane World Maker" \
		"Edit X-Plane scenery" \
		"" \
		"World-Maker" \
		"Application;Game;" \
		\
		false \
		"X-Plane" \
		"Fly with X-Plane" \
		"" \
		"X-Plane" \
		"Application;Game;" \
		false

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xfree86-3
.if defined(WITH_NVIDIA_GL)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri
.endif
.else
RUN_DEPENDS+=	${LINUXBASE}/lib/libGL.so.1:${PORTSDIR}/graphics/linux_glx
.endif

do-fetch:
	@if ! [ -e ${DISTDIR}/${DISTFILES} ]; then \
		${ECHO_CMD} "" ; \
		${ECHO_CMD} "The X-Plane distribution must be manually fetched with the X-Plane installer." ; \
		${ECHO_CMD} "To fetch the X-Plane distribution and create a tarball (for personal use only;" ; \
		${ECHO_CMD} "redistribution prohibited by license), do the following:" ; \
		${ECHO_CMD} "" ; \
		${ECHO_CMD} "  - install the games/linux-x-plane-net-installer port" ; \
		${ECHO_CMD} "  - as a normal user, run X-Plane-Net-Install, select a destination directory" ; \
		${ECHO_CMD} "    with enough free space (you need about 674 MB), and install X-Plane" ; \
		${ECHO_CMD} "  - as root, create the distribution tarball:" ; \
		${ECHO_CMD} "" ; \
		${ECHO_CMD} "      cd ${MASTERDIR}" ; \
		${ECHO_CMD} "      make dist XDISTDIR=/path/where/xplane/was/installed" ; \
		${ECHO_CMD} "" ; \
		${ECHO_CMD} "You can then remove XDISTDIR and install this port normally." ; \
		${ECHO_CMD} "" ; \
		${FALSE} ; \
	fi

dist:
.if defined(XDISTDIR)
.  if exists(${XDISTDIR}/X-Plane-athlon-xp) \
	|| exists(${XDISTDIR}/X-Plane-i586) \
	|| exists(${XDISTDIR}/X-Plane-pentium-3)
	@${ECHO_MSG} "===>  Packaging ${XDISTDIR} into ${DISTDIR}/${DISTFILES}"
	@cd ${XDISTDIR} && ${TAR} -ycf ${DISTDIR}/${DISTFILES} *
.  else
	@${ECHO_CMD} ""
	@${ECHO_CMD} "${XDISTDIR} does not appear to contain the X-Plane ${PORTVERSION} distribution."
	@${ECHO_CMD} ""
	@${FALSE}
.  endif
.else
	@${ECHO_CMD} ""
	@${ECHO_CMD} "XDISTDIR not defined."
	@${ECHO_CMD} ""
	@${ECHO_CMD} "You must point XDISTDIR to the path where you have installed the X-Plane"
	@${ECHO_CMD} "distribution with the installer, for instance:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "  make dist XDISTDIR=/tmp/X-Plane"
	@${ECHO_CMD} ""
	@${FALSE}
.endif

post-patch:
	@${FIND} ${WRKSRC} -type d -empty -exec ${TOUCH} "{}/.keep_me" \;
	@${MKDIR} ${WRKSRC}/.programs
.for p in ${PROGRAMS}
	@${MV} -f ${WRKSRC}/${p}-* ${WRKSRC}/.programs
.endfor

pre-install:
	@${MKDIR} ${WRKDIR}/.wrapper
	@${MV} -f ${WRKDIR}/x-plane-wrapper ${WRKDIR}/.wrapper
	@${RM} -f ${PLIST}
	@${RM} -f ${PLIST}.dirs
.for d in "" .programs
	@cd ${WRKSRC}/${d} && \
	${FIND} * -type f | ${SORT} | ${SED} -e 's|^|${XDIR_REL}/|' >> ${PLIST} && \
	${FIND} * -type d >> ${PLIST}.dirs
.endfor
	@${SORT} -ru ${PLIST}.dirs | ${SED} -e 's|^|@dirrm ${XDIR_REL}/|' >> ${PLIST}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/.wrapper/x-plane-wrapper ${PREFIX}/libexec
.for p in ${PROGRAMS}
	${LN} -sf ${PREFIX}/libexec/x-plane-wrapper ${PREFIX}/bin/${p}
.endfor
.for d in "" .programs
	cd ${WRKSRC}/${d} && ${FIND} * -type d -exec ${MKDIR} "${XDIR}/{}" \;
.endfor
	cd ${WRKSRC} && ${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${XDIR}/{}" \;
	cd ${WRKSRC}/.programs && ${FIND} * -type f -exec ${INSTALL_PROGRAM} "{}" "${XDIR}/{}" \;

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
