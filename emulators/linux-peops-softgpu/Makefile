# New ports collection makefile for:	linux-peops-softgpu
# Date created:			21 Dec 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	peops-softgpu
PORTVERSION=	1.16
CATEGORIES=	emulators linux
MASTER_SITES=	http://www.pbernert.com/
PKGNAMEPREFIX=	linux-
DISTNAME=	gpupeopssoftx${MAJOR}${MINOR}

MAINTAINER=	jylefort@brutele.be
COMMENT=	A PSEmu Pro GPU plugin using a software X11 renderer (Linux version)

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

ONLY_FOR_ARCHS=	i386

# Linux binary should not be stripped by INSTALL_PROGRAM
# because as a side effect it brands the binary as FreeBSD.
STRIP=

MAJOR=		${PORTVERSION:R}
MINOR=		${PORTVERSION:E}
PLIST_SUB+=	MAJOR=${MAJOR} MINOR=${MINOR}

.include <bsd.port.pre.mk>

PSEMUPRO_PLUGINS_DIR=	${LOCALBASE}/lib/psemupro/plugins
PSEMUPRO_CFGBINS_DIR=	${LOCALBASE}/libexec/psemupro/cfg
PSEMUPRO_CFGFILES_DIR=	${LOCALBASE}/share/psemupro/cfg

do-install:
	${MKDIR} ${PSEMUPRO_PLUGINS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/libgpuPeopsSoftX.so.${MAJOR}.0.${MINOR} ${PSEMUPRO_PLUGINS_DIR}

	${MKDIR} ${PSEMUPRO_CFGBINS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/cfgPeopsSoft ${PSEMUPRO_CFGBINS_DIR}

	${MKDIR} ${PSEMUPRO_CFGFILES_DIR}
	${INSTALL_DATA} ${WRKSRC}/gpuPeopsSoftX.cfg ${PSEMUPRO_CFGFILES_DIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/peops_soft_readme_${MAJOR}_${MINOR}.txt \
		${WRKSRC}/peops_soft_version_${MAJOR}_${MINOR}.txt \
		${DOCSDIR}
.endif

.include <bsd.port.post.mk>
