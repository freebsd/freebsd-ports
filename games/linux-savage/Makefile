# New ports collection makefile for:	linux-savage
# Date created:		2006-09-06
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	savage
PORTVERSION=	2.00e
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	http://www.notforidiots.com/SFE/ \
		http://www.newerth.com/downloads/ \
		http://newerth.downloads.groentjuh.eu/ \
		http://guf.newerth.com/downloads/ \
		http://mnky.newerth.com/
PKGNAMEPREFIX=	linux-
DISTFILES=	SFE-Standalone${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The Savage game (linux version)

USE_LINUX=	yes
USE_LINUX_APPS=	libvorbis tiff
NO_BUILD=	yes
RESTRICTED=	Savage is freeware, but i am not sure of its license
NO_PACKAGE=	Package will be 150MB, set FORCE_PACKAGE if you really want it
PLIST_SUB+=	SAVAGEDIR="${SAVAGEDIR}"
SUB_FILES=	pkg-message savage savage_editor
SUB_LIST+=	SAVAGEDIR="${PREFIX}/${SAVAGEDIR}"
DOCSDIR=	share/doc/${PKGNAMEPREFIX}${PORTNAME}
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}

SAVAGEDIR=	lib/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS=	NVIDIA_GL	"Install support for nvidia"	off

.include <bsd.port.pre.mk>

.if defined(WITH_NVIDIA_GL)
.	if !exists(${LINUXBASE}/usr/X11R6/lib/libGL.so.1)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver \
		${LINUXBASE}/usr/X11R6/lib/libGLU.so.1:${PORTSDIR}/graphics/linux-libGLU
.	endif
.else
USE_LINUX_APPS+=dri
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && \
		${TAR} xfz ${_DISTDIR}/${DISTFILES} --directory ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/${SAVAGEDIR}
.for DIRE in graveyard game
	@${MKDIR} ${PREFIX}/${SAVAGEDIR}/${DIRE}
	@cd ${WRKSRC}/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${PREFIX}/${SAVAGEDIR}/${DIRE}/{}" \; && \
			${FIND} * -type f -name "*.so" -exec ${INSTALL_PROGRAM} "{}" \
				"${PREFIX}/${SAVAGEDIR}/${DIRE}/{}" \; && \
				${FIND} -E * -type f -iregex ".*\.(cfg|dat|db|dll|jpg|mcfg|objgroup|ogg|tga|txt|ttf|s2g|s2z)" \
					-exec ${INSTALL_DATA} "{}" "${PREFIX}/${SAVAGEDIR}/${DIRE}/{}" \;
.endfor
	@${MKDIR} ${PREFIX}/${SAVAGEDIR}/libs
	@cd ${WRKSRC}/libs && \
		${FIND} * -type f -exec ${INSTALL_PROGRAM} "{}" "${PREFIX}/${SAVAGEDIR}/libs/{}" \;

	${INSTALL_PROGRAM} ${WRKSRC}/silverback.bin ${PREFIX}/${SAVAGEDIR}

.for FILE in savage savage_editor
	${INSTALL_SCRIPT} ${WRKDIR}/${FILE} ${PREFIX}/bin/${PKGNAMEPREFIX}${FILE}
.endfor
	${LN} -s ${PREFIX}/${SAVAGEDIR}/libs/libfmod-3.75.so ${PREFIX}/${SAVAGEDIR}/libs/libfmod.so

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/licenses.txt ${PREFIX}/${DOCSDIR}
.endif

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
