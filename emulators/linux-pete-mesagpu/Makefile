# New ports collection makefile for:	linux-pete-mesagpu
# Date created:			23 Dec 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	pete-mesagpu
PORTVERSION=	1.75
CATEGORIES=	emulators linux
MASTER_SITES=	http://home.t-online.de/home/PeteBernert/
PKGNAMEPREFIX=	linux-
DISTNAME=	gpupetemesagl175

MAINTAINER=	jylefort@brutele.be
COMMENT=	A PSEmu Pro GPU plugin using an OpenGL renderer (Linux version)

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk \
		${LINUXBASE}/usr/X11R6/lib/libGL.so:${PORTSDIR}/graphics/linux_mesa3

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

ONLY_FOR_ARCHS=	i386

# Linux binary should not be stripped by INSTALL_PROGRAM
# because as a side effect it brands the binary as FreeBSD.
STRIP=

.include <bsd.port.pre.mk>

PSEMUPRO_PLUGINS_DIR=	${LOCALBASE}/lib/psemupro/plugins
PSEMUPRO_CFGBINS_DIR=	${LOCALBASE}/libexec/psemupro/cfg
PSEMUPRO_CFGFILES_DIR=	${LOCALBASE}/share/psemupro/cfg

do-install:
	${MKDIR} ${PSEMUPRO_PLUGINS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/libgpuPeteMesaGL.so.1.0.75 ${PSEMUPRO_PLUGINS_DIR}

	${MKDIR} ${PSEMUPRO_CFGBINS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/cfgPeteMesaGL ${PSEMUPRO_CFGBINS_DIR}

	${MKDIR} ${PSEMUPRO_CFGFILES_DIR}
	${INSTALL_DATA} ${WRKSRC}/gpuPeteMesaGL.cfg ${PSEMUPRO_CFGFILES_DIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/readme.txt \
		${WRKSRC}/version.txt \
		${DOCSDIR}
.endif

.include <bsd.port.post.mk>
