# New ports collection makefile for:	linux-savage-samuraiwars
# Date created:		2007-09-08
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	savage-samuraiwars
PORTVERSION=	2.00c
CATEGORIES=	games linux
MASTER_SITES=	http://www.newerth.com/downloads/ \
		http://newerth.downloads.groentjuh.eu/ \
		http://guf.newerth.com/downloads/ \
		http://mnky.newerth.com/
PKGNAMEPREFIX=	linux-
DISTFILES=	SamuraiWars-Linux${EXTRACT_SUFX}
DIST_SUBDIR=	savage

MAINTAINER=	acm@FreeBSD.org
COMMENT=	An official mod for Savage game (linux version)

USE_BZIP2=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	libvorbis tiff
NO_BUILD=	yes
RESTRICTED=	SamuraiWars is freeware, but i am not sure of its license
NO_PACKAGE=	Package will be 350MB, set FORCE_PACKAGE if you really want it
PLIST_SUB+=	SAMURAIWARSDIR="${SAMURAIWARSDIR}"
SUB_FILES=	pkg-message samuraiwars samuraiwars_server
SUB_LIST+=	SAMURAIWARSDIR="${PREFIX}/${SAMURAIWARSDIR}"
DOCSDIR=	share/doc/${PKGNAMEPREFIX}${PORTNAME}
WRKSRC=		${WRKDIR}/SamuraiWars

SAMURAIWARSDIR=	lib/${PKGNAMEPREFIX}${PORTNAME}

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

do-install:
	@${MKDIR} ${PREFIX}/${SAMURAIWARSDIR}
.for DIRE in game samuraiwars updater
	@${MKDIR} ${PREFIX}/${SAMURAIWARSDIR}/${DIRE}
	@cd ${WRKSRC}/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${PREFIX}/${SAMURAIWARSDIR}/${DIRE}/{}" \; && \
			${FIND} * -type f -name "*.so" -exec ${INSTALL_PROGRAM} "{}" \
				"${PREFIX}/${SAMURAIWARSDIR}/${DIRE}/{}" \; && \
				${FIND} -E * -type f -iregex ".*\.(bik|cfg|db|dll|ogg|tga|thumb|txt|ttf|s2z)" \
					-exec ${INSTALL_DATA} "{}" "${PREFIX}/${SAMURAIWARSDIR}/${DIRE}/{}" \;
.endfor
	@${MKDIR} ${PREFIX}/${SAMURAIWARSDIR}/libs
	@cd ${WRKSRC}/libs && \
		${FIND} * -type f -exec ${INSTALL_PROGRAM} "{}" "${PREFIX}/${SAMURAIWARSDIR}/libs/{}" \;

.for FILE in dedicated_server.bin savage.bin silverback.bin update
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${PREFIX}/${SAMURAIWARSDIR}
.endfor

.for FILE in samuraiwars samuraiwars_server
	${INSTALL_SCRIPT} ${WRKDIR}/${FILE} ${PREFIX}/bin/${PKGNAMEPREFIX}${FILE}
.endfor

.for FILE in agp_error.txt icon.xpm logo.png eula.txt
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/${SAMURAIWARSDIR}
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOCSDIR}
.	for FILE in commander_controls.txt licenses.txt
		${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/${DOCSDIR}
.	endfor
.endif

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
