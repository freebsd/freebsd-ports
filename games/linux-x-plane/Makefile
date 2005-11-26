# New ports collection makefile for:	linux-x-plane
# Date created:				25 Nov 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linux-x-plane
PORTVERSION=	8.16
CATEGORIES=	games linux
MASTER_SITES=	http://66.111.223.52/ \
		ftp://ftp.x-plane.com/Web_Links/
DISTNAME=	XLIN${XPVERSION}b

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A commercial flight simulator

RUN_DEPENDS=	${LINUXBASE}/lib/libgcc/libgcc_s.so.1:${PORTSDIR}/lang/linux-libgcc \
		${LINUXBASE}/usr/lib/libopenal.so.0:${PORTSDIR}/audio/linux-openal \
		${LINUXBASE}/usr/X11R6/lib/libGLU.so.1.3:${PORTSDIR}/graphics/linux_dri

WRKSRC=		${WRKDIR}/X-System-${XPVERSION}-lin1
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_LINUX=	yes
NO_BUILD=	yes
RESTRICTED=	"Redistribution prohibited"
ONLY_FOR_ARCHS=	i386

XPVERSION=	${PORTVERSION:S|.||g}

XDIR=		${PREFIX}/lib/x-plane
XDIR_REL=	${XDIR:S,^${PREFIX}/,,}

PROGRAMS=	Airfoil-Maker Briefer Plane-Maker World-Maker X-Plane

PLIST=		${WRKDIR}/pkg-plist
PLIST_FILES=	${PROGRAMS:S|^|bin/|} libexec/x-plane-wrapper
PLIST_DIRS=	${XDIR_REL}

SUB_FILES=	x-plane-wrapper
SUB_LIST=	XDIR="${XDIR}" PORTVERSION="${PORTVERSION}" XPVERSION="${XPVERSION}"

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

post-patch:
	@${FIND} ${WRKSRC} -type d -empty -exec ${TOUCH} "{}/.keep_me" \;
	@${MKDIR} ${WRKSRC}/.programs/Resources
	@${MV} -f ${WRKSRC}/Resources/plugins ${WRKSRC}/.programs/Resources
.for p in ${PROGRAMS}
	@${MV} -f ${WRKSRC}/${p}-* ${WRKSRC}/.programs
.endfor

pre-install:
	@${RM} -f ${PLIST}
	@${RM} -f ${PLIST}.dirs
.for d in "" .programs
	@cd ${WRKSRC}/${d} && \
	${FIND} * -type f | ${SORT} | ${SED} -e 's|^|${XDIR_REL}/|' >> ${PLIST} && \
	${FIND} * -type d >> ${PLIST}.dirs
.endfor
	@${SORT} -ru ${PLIST}.dirs | ${SED} -e 's|^|@dirrm ${XDIR_REL}/|' >> ${PLIST}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/x-plane-wrapper ${PREFIX}/libexec
.for p in ${PROGRAMS}
	${LN} -sf ${PREFIX}/libexec/x-plane-wrapper ${PREFIX}/bin/${p}
.endfor
.for d in "" .programs
	cd ${WRKSRC}/${d} && ${FIND} * -type d -exec ${MKDIR} "${XDIR}/{}" \;
.endfor
	cd ${WRKSRC} && ${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${XDIR}/{}" \;
	cd ${WRKSRC}/.programs && ${FIND} * -type f -exec ${INSTALL_PROGRAM} "{}" "${XDIR}/{}" \;
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
