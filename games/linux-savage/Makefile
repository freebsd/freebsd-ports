# New ports collection makefile for:	linux-savage
# Date created:		2006-09-06
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	savage
PORTVERSION=	2.00c
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	http://downloads.s2games.com/online_orders/:full \
		http://patches.s2games.com/:patch
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME:S/$/_/}
DISTFILES=	${DISTNAME:S/$/linux/}.sh.gz:full \
		${PORTNAME}20030905a-patch.tar.gz:patch \
		${PORTNAME}20030905d-patch.tar.gz:patch \
		${PORTNAME}20030908a-patch.tar.gz:patch \
		${PORTNAME}20031004b-patch.tar.gz:patch \
		${PORTNAME}20031022a-patch.tar.gz:patch
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The Savage game (linux version)

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libvorbis.so.0:${PORTSDIR}/audio/linux-libvorbis \
		${LINUXBASE}/usr/lib/libtiff.so.3:${PORTSDIR}/graphics/linux-tiff

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
NO_BUILD=	yes
RESTRICTED=	Savage is freeware, but i am not sure of its license
NO_PACKAGE=	Package will be 350MB, set FORCE_PACKAGE if you really want it
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}
SAVAGEDIR=	lib/${PKGNAMEPREFIX}${PORTNAME}

SUB_FILES=	pkg-message savage savage_editor savage_server
PLIST_SUB+=	SAVAGEDIR="${SAVAGEDIR}"
SUB_LIST+=	SAVAGEDIR="${PREFIX}/${SAVAGEDIR}"

OPTIONS=	NVIDIA	"Install support for nvidia"	off

.include <bsd.port.pre.mk>

.if defined(WITH_NVIDIA)
.	if !exists(${LINUXBASE}/usr/lib/libGL.so.1)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.	endif
.else
.	if !exists(${LINUXBASE}/usr/X11R6/lib/libGL.so.1)
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri
.	endif
.endif

do-extract:
# Extract savage base
	@${MKDIR} ${WRKSRC}
	@${GZIP_CMD} -dc ${_DISTDIR}/${DISTNAME:S/$/linux/}.sh.gz > \
		${WRKDIR}/${DISTNAME:S/$/linux/}.sh
	@cd ${WRKSRC} && \
		${TAIL} +175 ${WRKDIR}/${DISTNAME:S/$/linux/}.sh | \
			${GZIP_CMD} -dc | ${TAR} xf -
# Extract savage 2.00c
	@${MKDIR} ${WRKDIR}/patch
.for FILE in 20030905a 20030905d 20030908a 20031004b 20031022a
	@${TAR} xfz ${_DISTDIR}/savage${FILE}-patch.tar.gz --directory ${WRKDIR}/patch
.endfor

post-extract:
	@${CP} -Rf ${WRKSRC}/linux/* ${WRKSRC}/Savage/
	@${CP} -Rf ${WRKSRC}/bin/x86/* ${WRKSRC}/Savage/
	@${MV} ${WRKDIR}/patch/savage.bin.new ${WRKDIR}/patch/savage.bin
	@${CP} -Rf ${WRKDIR}/patch/* ${WRKSRC}/Savage/
	@${FIND} -E ${WRKSRC}/Savage -type f -iregex ".*\.(dll|exe|bat)" -exec ${RM} "{}" \;
	@${FIND} ${WRKSRC}/Savage -type d -name CVS | ${XARGS} ${RM} -rf

do-install:
	@${MKDIR} ${PREFIX}/${SAVAGEDIR}
.for DIRE in editor game updater
	@${MKDIR} ${PREFIX}/${SAVAGEDIR}/${DIRE}
	@cd ${WRKSRC}/Savage/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${PREFIX}/${SAVAGEDIR}/${DIRE}/{}" \; && \
			${FIND} * -type f -name "*.so" -exec ${INSTALL_PROGRAM} "{}" \
				"${PREFIX}/${SAVAGEDIR}/${DIRE}/{}" \; && \
				${FIND} -E * -type f -iregex ".*\.(bik|cfg|tga|txt|ttf|s2g|s2z|ogg)" \
					-exec ${INSTALL_DATA} "{}" "${PREFIX}/${SAVAGEDIR}/${DIRE}/{}" \;
.endfor
	@${MKDIR} ${PREFIX}/${SAVAGEDIR}/libs
	@cd ${WRKSRC}/Savage/libs && \
		${FIND} * -type f -exec ${INSTALL_PROGRAM} "{}" "${PREFIX}/${SAVAGEDIR}/libs/{}" \;

.for FILE in dedicated_server.bin savage savage.bin silverback.bin update
	${INSTALL_PROGRAM} ${WRKSRC}/Savage/${FILE} ${PREFIX}/${SAVAGEDIR}
.endfor

.for FILE in savage savage_editor savage_server
	${INSTALL_SCRIPT} ${WRKDIR}/${FILE} ${PREFIX}/bin/${PKGNAMEPREFIX}${FILE}
.endfor

.for FILE in agp_error.txt icon.xpm logo.png eula.txt
	${INSTALL_DATA} ${WRKSRC}/Savage/${FILE} ${PREFIX}/${SAVAGEDIR}
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Savage/docs/* ${DOCSDIR}
.endif

post-install:
	@PKG_PREFIX=${PREFIX}/${SAVAGEDIR} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
