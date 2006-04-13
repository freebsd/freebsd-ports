# New ports collection makefile for:	linux-padjoy
# Date created:			13 Apr 2006
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	padjoy
PORTVERSION=	0.8.1
CATEGORIES=	emulators linux
MASTER_SITES=	http://members.chello.at/erich.kitzmueller/ammoq/
PKGNAMEPREFIX=	linux-
DISTNAME=	padJoy${MAJOR}${MINOR}${MICRO}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A PSEmu Pro joystick plugin (Linux version)

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk \
		/boot/modules/linux_js.ko:${PORTSDIR}/devel/linux-js

WRKSRC=		${WRKDIR}/padJoy
NO_BUILD=	yes
USE_LINUX=	yes
USE_X_PREFIX=	yes

ONLY_FOR_ARCHS=	i386 amd64

MAJOR=		${PORTVERSION:R:R}
MINOR=		${PORTVERSION:R:E}
MICRO=		${PORTVERSION:E}
PLIST_SUB=	MAJOR=${MAJOR} MINOR=${MINOR}

PSEMUPRO_PLUGINS_DIR=	${PREFIX}/lib/psemupro/plugins
PSEMUPRO_CFGBINS_DIR=	${PREFIX}/libexec/psemupro/cfg

do-install:
	${MKDIR} ${PSEMUPRO_PLUGINS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/libpadJoy-${MAJOR}.${MINOR}.so ${PSEMUPRO_PLUGINS_DIR}

	${MKDIR} ${PSEMUPRO_CFGBINS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cfgPadJoy ${PSEMUPRO_CFGBINS_DIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
