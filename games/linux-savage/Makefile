# New ports collection makefile for:	linux-savage
# Date created:		2006-09-06
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	savage
PORTVERSION=	2.00e
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	http://www.happypuppy.com/s2games/:full \
		http://www.notforidiots.com/autoupdater/:patch
PKGNAMEPREFIX=	linux-
DISTFILES=	${PORTNAME:S/s/S/}_with_sep3t.run:full \
		SEP-3T_3T+-r2.tar.gz:patch \
		SEP-3T+-Crash-Hotfix-Linux.tar.gz:patch
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The Savage game (linux version)

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libvorbis.so.0:${PORTSDIR}/audio/linux-libvorbis \
		${LINUXBASE}/usr/lib/libtiff.so.3:${PORTSDIR}/graphics/linux-tiff

USE_LINUX=	yes
NO_BUILD=	yes
RESTRICTED=	Savage is freeware, but i am not sure of its license
NO_PACKAGE=	Package will be 350MB, set FORCE_PACKAGE if you really want it
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}
SAVAGEDIR=	lib/${PKGNAMEPREFIX}${PORTNAME}

SUB_FILES=	pkg-message savage savage_editor savage_server
PLIST_SUB+=	SAVAGEDIR="${SAVAGEDIR}"
SUB_LIST+=	SAVAGEDIR="${PREFIX}/${SAVAGEDIR}"

OPTIONS=	NVIDIA_GL	"Install support for nvidia"	off

.include <bsd.port.pre.mk>

.if defined(WITH_NVIDIA_GL)
.	if !exists(${LINUXBASE}/usr/X11R6/lib/libGL.so.1)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver \
		${LINUXBASE}/usr/X11R6/lib/libGLU.so.1:${PORTSDIR}/graphics/linux-libGLU
.	endif
.else
.	if !exists(${LINUXBASE}/usr/lib/libGL.so.1)
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri
.	endif
.endif

do-extract:
# Extract savage 2.00e
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && \
		${TAIL} +402 ${_DISTDIR}/${PORTNAME:S/s/S/}_with_sep3t.run | ${TAR} xf -
.for FILE in graveyard savage
	@${TAR} xfj ${WRKSRC}/${FILE}.tar.bz2 --directory ${WRKSRC}
.endfor

.for FILE in libcrypto libcurl libfmod libfreetype libglib libgssapi_krb5 libk5crypto \
	libkrb5 libpng libssl libstdc++
	@${RM} ${WRKSRC}/libs/${FILE}*
.endfor

# Extract SEP patch
	@${TAR} xfz ${_DISTDIR}/SEP-3T_3T+-r2.tar.gz --directory ${WRKSRC}
	@${TAR} xfz ${_DISTDIR}/SEP-3T+-Crash-Hotfix-Linux.tar.gz --directory ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/${SAVAGEDIR}
.for DIRE in graveyard game updater
	@${MKDIR} ${PREFIX}/${SAVAGEDIR}/${DIRE}
	@cd ${WRKSRC}/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${PREFIX}/${SAVAGEDIR}/${DIRE}/{}" \; && \
			${FIND} * -type f -name "*.so" -exec ${INSTALL_PROGRAM} "{}" \
				"${PREFIX}/${SAVAGEDIR}/${DIRE}/{}" \; && \
				${FIND} -E * -type f -iregex ".*\.(bik|cfg|dat|db|tga|txt|ttf|s2g|s2z|ogg)" \
					-exec ${INSTALL_DATA} "{}" "${PREFIX}/${SAVAGEDIR}/${DIRE}/{}" \;
.endfor
	@${MKDIR} ${PREFIX}/${SAVAGEDIR}/libs
	@cd ${WRKSRC}/libs && \
		${FIND} * -type f -exec ${INSTALL_PROGRAM} "{}" "${PREFIX}/${SAVAGEDIR}/libs/{}" \;

.for FILE in silverback.bin sep_dedicated.bin update
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${PREFIX}/${SAVAGEDIR}
.endfor

.for FILE in savage savage_editor savage_server
	${INSTALL_SCRIPT} ${WRKDIR}/${FILE} ${PREFIX}/bin/${PKGNAMEPREFIX}${FILE}
.endfor

.for FILE in agp_error.txt icon.xpm logo.png eula.txt
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/${SAVAGEDIR}
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.	for FILE in README commander_controls.txt licenses.txt
		${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.	endfor
.endif

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
