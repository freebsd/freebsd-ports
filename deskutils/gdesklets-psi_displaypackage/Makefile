# New ports collection makefile for:	gdesklets-psi_displaypackage
# Date created:				21 September 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	displaypackage
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-psi_
DISTNAME=	PsiDisplayPackage-${DISTVERSION}

MAINTAINER=	klammer@webonaut.com
COMMENT=	The Psi Display Package

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets \
		${DATADIR}/Sensors/CPU/__init__.py:${PORTSDIR}/sysutils/gdesklets-sensor-psi_cpu \
		${DATADIR}/Sensors/Disk/__init__.py:${PORTSDIR}/sysutils/gdesklets-sensor-psi_disk \
		${DATADIR}/Sensors/ExternalInterval/__init__.py:${PORTSDIR}/deskutils/gdesklets-sensor-psi_externalinterval \
		${DATADIR}/Sensors/Memo/__init__.py:${PORTSDIR}/deskutils/gdesklets-sensor-psi_memo \
		${DATADIR}/Sensors/MemoOver/__init__.py:${PORTSDIR}/deskutils/gdesklets-sensor-psi_memoover \
		${DATADIR}/Sensors/Memory/__init__.py:${PORTSDIR}/sysutils/gdesklets-sensor-psi_memory \
		${DATADIR}/Sensors/Network/__init__.py:${PORTSDIR}/net/gdesklets-sensor-psi_network \
		${DATADIR}/Sensors/Ping/__init__.py:${PORTSDIR}/net/gdesklets-sensor-psi_ping \
		${DATADIR}/Sensors/popmail/__init__.py:${PORTSDIR}/mail/gdesklets-sensor-psi_popmail \
		${DATADIR}/Sensors/Theme/__init__.py:${PORTSDIR}/deskutils/gdesklets-sensor-psi_theme \
		${DATADIR}/Sensors/VariableBorder/__init__.py:${PORTSDIR}/deskutils/gdesklets-sensor-psi_variableborder \
		${DATADIR}/Sensors/IconButton/__init__.py:${PORTSDIR}/deskutils/gdesklets-sensor-psi_iconbutton

USE_BZIP2=	yes
USE_X_PREFIX=	yes

DISTVERSION=	20031028
NAME=		psi-displays
DATADIR=	${PREFIX}/share/gnome/gdesklets
WRKSRC=		${WRKDIR}/${NAME}-v${PORTVERSION}
NO_BUILD=	yes

do-install:
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${MKDIR} ${DATADIR}/Displays/${NAME}
	@${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/Displays/${NAME}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
