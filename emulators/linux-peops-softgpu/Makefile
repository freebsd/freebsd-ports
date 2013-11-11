# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	peops-softgpu
PORTVERSION=	${SOFTGPU_VERSION}
CATEGORIES=	emulators linux
MASTER_SITES=	http://www.pbernert.com/
PKGNAMEPREFIX=	linux-
DISTFILES=	gpupeopssoftx${MAJOR}${MINOR}${EXTRACT_SUFX} \
		${CFG_DISTFILE}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	PSEmu Pro GPU plugin using a software X11 renderer (Linux version)

DEPRECATED=	Depends on deprecated Linux GTK1
EXPIRATION_DATE=2013-12-01

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	gtk xorglibs
PORTDOCS=	*

ONLY_FOR_ARCHS=	i386 amd64

MAJOR=		${PORTVERSION:R}
MINOR=		${PORTVERSION:E}
PLIST_SUB+=	MAJOR=${MAJOR} MINOR=${MINOR}

PSEMUPRO_PLUGINS_DIR=	${PREFIX}/lib/psemupro/plugins
PSEMUPRO_CFGBINS_DIR=	${PREFIX}/libexec/psemupro/cfg
PSEMUPRO_CFGFILES_DIR=	${PREFIX}/share/psemupro/cfg

NO_STAGE=	yes
.include <bsd.port.options.mk>

.include "${.CURDIR}/../linux-pete-xgl2gpu/Makefile.inc"

do-install:
	${MKDIR} ${PSEMUPRO_PLUGINS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/libgpuPeopsSoftX.so.${MAJOR}.0.${MINOR} ${PSEMUPRO_PLUGINS_DIR}

	${MKDIR} ${PSEMUPRO_CFGBINS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/cfg/cfgPeopsSoft ${PSEMUPRO_CFGBINS_DIR}

	${MKDIR} ${PSEMUPRO_CFGFILES_DIR}
	${INSTALL_DATA} ${WRKSRC}/gpuPeopsSoftX.cfg ${PSEMUPRO_CFGFILES_DIR}

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
