# New ports collection makefile for:	linux-peops-softgpu
# Date created:			21 Dec 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	softgpu
PORTVERSION=	1.12
CATEGORIES=	emulators linux
MASTER_SITES=	http://home.t-online.de/home/PeteBernert/
PKGNAMEPREFIX=	linux-peops-
DISTNAME=	gpupeopssoftx112

MAINTAINER=	jylefort@brutele.be

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

ONLY_FOR_ARCHS=	i386

# Linux binary should not be stripped by INSTALL_PROGRAM
# because as a side effect it brands the binary as FreeBSD.
STRIP=

.include <bsd.port.pre.mk>

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

PSEMUPRO_PLUGINS_DIR=	${LOCALBASE}/lib/linux-psemupro/plugins
PSEMUPRO_CFGBINS_DIR=	${LOCALBASE}/libexec/linux-psemupro/cfg
PSEMUPRO_CFGFILES_DIR=	${LOCALBASE}/share/linux-psemupro/cfg

do-install:
	${MKDIR} ${PSEMUPRO_PLUGINS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/libgpuPeopsSoftX.so.1.0.12 ${PSEMUPRO_PLUGINS_DIR}

	${MKDIR} ${PSEMUPRO_CFGBINS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/cfgPeopsSoft ${PSEMUPRO_CFGBINS_DIR}

	${MKDIR} ${PSEMUPRO_CFGFILES_DIR}
	${INSTALL_DATA} ${WRKSRC}/gpuPeopsSoftX.cfg ${PSEMUPRO_CFGFILES_DIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/readme_1_12.txt \
		${WRKSRC}/version_1_12.txt \
		${DOCSDIR}
.endif

.include <bsd.port.post.mk>
