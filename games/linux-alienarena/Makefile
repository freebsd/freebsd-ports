# New ports collection makefile for:	Alien Arena 2006
# Date created:		2005-11-12
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	alienarena
PORTVERSION=	2006
CATEGORIES=	games linux
MASTER_SITES=	http://www.forsakenweb.com/gamepage/loaders/games/:full \
		ftp://download1.gamershell.com/pub/pc/games/gamershell/demo/:full \
		ftp://download2.gamershell.com/pub/pc/games/gamershell/demo/:full \
		ftp://download4.gamershell.com/pub/pc/games/gamershell/demo/:full \
		ftp://download6.gamershell.com/pub/pc/games/gamershell/demo/:full \
		ftp://download7.gamershell.com/pub/pc/games/gamershell/demo/:full \
		ftp://download9.gamershell.com/pub/pc/games/gamershell/demo/:full \
		ftp://download11.gamershell.com/pub/pc/gamershell/demo/:full \
		ftp://download12.gamershell.com/pub/pc/gamershell/demo/:full \
		http://offload1.icculus.org/~ravage/alienarena2006/:patch
PKGNAMEPREFIX=	linux-
DISTFILES=	${PORTNAME}-${PORTVERSION}-x86.run:full \
		${PORTNAME}-${PORTVERSION}-sdl-i386.tar.gz:patch \
		${PORTNAME}-${PORTVERSION}-sdl-x86_64.tar.gz:patch

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Alien Arena 2006 (Linux version)

RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libGLU.so.1.3:${PORTSDIR}/graphics/linux_dri \
		${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12

ONLY_FOR_ARCHS=	i386 amd64
USE_X_PREFIX=	yes
USE_LINUX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
RESTRICTED=	"Redistribution is limited, see license"
NO_PACKAGE=	"Package will be 150MB, set FORCE_PACKAGE if you really want to build it"

ALIENDIR=	${PREFIX}/lib/${PORTNAME}
ALIENDIR_REL=	${ALIENDIR:S,^${PREFIX}/,,}
LIBDIRS=	arena botinfo data1

SUB_FILES=	AlienArena AlienArenaDedicated

PLIST=		${WRKDIR}/pkg-plist
PLIST_FILES=	bin/AlienArena bin/AlienArenaDedicated \
		${ALIENDIR_REL}/crded ${ALIENDIR_REL}/crx \
		share/pixmaps/alienarena.xpm
PLIST_DIRS=	${ALIENDIR_REL}
PORTDOCS=	README.txt

DESKTOP_ENTRIES="Alien Arena 2006" \
		"Play Alien Arena 2006" \
		"alienarena.xpm" \
		"AlienArena" \
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

.if ${ARCH} == "i386"
ENGINE_ARCH=	x86
SDL_ARCH=	i386
.elif ${ARCH} == "amd64"
ENGINE_ARCH=	x86_64
SDL_ARCH=	x86_64
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && \
		${TAIL} -c +8778 ${_DISTDIR}/${PORTNAME}-${PORTVERSION}-x86.run | ${TAR} xfz -
	@${TAR} xfj ${WRKSRC}/alienarena-2006-data.tar.bz2 -C ${WRKSRC}

	@${CP} -R ${WRKSRC}/engine/${ENGINE_ARCH}/* ${WRKSRC}
	@${TAR} xfz ${_DISTDIR}/${PORTNAME}-${PORTVERSION}-sdl-${SDL_ARCH}.tar.gz -C ${WRKSRC}

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} ${LIBDIRS} -type f | ${SORT} \
		| ${SED} -e 's|^|${ALIENDIR_REL}/|' >> ${PLIST} && \
	${FIND} ${LIBDIRS} -type d | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm ${ALIENDIR_REL}/|' >> ${PLIST}

do-install:
	cd ${WRKSRC} && \
	${FIND} ${LIBDIRS} -type d -exec ${MKDIR} "${ALIENDIR}/{}" \; && \
	${FIND} ${LIBDIRS} -type f -exec ${INSTALL_DATA} "{}" "${ALIENDIR}/{}" \;

	${INSTALL_SCRIPT} ${WRKDIR}/AlienArena ${WRKDIR}/AlienArenaDedicated ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/crded ${WRKSRC}/crx ${ALIENDIR}

	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/alienarena.xpm ${PREFIX}/share/pixmaps

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
