# New ports collection makefile for:	linux-peops-softgpu
# Date created:			21 Dec 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	peops-softgpu
PORTVERSION=	1.17
CATEGORIES=	emulators linux
MASTER_SITES=	http://www.pbernert.com/
PKGNAMEPREFIX=	linux-
DISTNAME=	gpupeopssoftx${MAJOR}${MINOR}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A PSEmu Pro GPU plugin using a software X11 renderer (Linux version)

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_LINUX=	yes
USE_X_PREFIX=	yes

ONLY_FOR_ARCHS=	i386

MAJOR=		${PORTVERSION:R}
MINOR=		${PORTVERSION:E}
PLIST_SUB+=	MAJOR=${MAJOR} MINOR=${MINOR}

PSEMUPRO_PLUGINS_DIR=	${PREFIX}/lib/psemupro/plugins
PSEMUPRO_CFGBINS_DIR=	${PREFIX}/libexec/psemupro/cfg
PSEMUPRO_CFGFILES_DIR=	${PREFIX}/share/psemupro/cfg

do-install:
	${MKDIR} ${PSEMUPRO_PLUGINS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/libgpuPeopsSoftX.so.${MAJOR}.0.${MINOR} ${PSEMUPRO_PLUGINS_DIR}

	${MKDIR} ${PSEMUPRO_CFGBINS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/cfgPeopsSoft ${PSEMUPRO_CFGBINS_DIR}

	${MKDIR} ${PSEMUPRO_CFGFILES_DIR}
	${INSTALL_DATA} ${WRKSRC}/gpuPeopsSoftX.cfg ${PSEMUPRO_CFGFILES_DIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
