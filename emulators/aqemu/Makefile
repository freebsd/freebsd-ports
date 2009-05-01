# New ports collection makefile for:	aqemu
# Date created:		2008-09-03
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aqemu
PORTVERSION=	0.7.1
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt4 based Qemu frontend

LIB_DEPENDS=	vncclient.0:${PORTSDIR}/net/libvncserver

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui qtestlib xml qmake_build uic_build moc_build rcc_build
HAS_CONFIGURE=	yes

QMAKE_ARGS=	-unix -recursive ${QMAKE_PRO}
QMAKE_PRO=	AQEMU.pro

QT_LRELEASE=	${LOCALBASE}/bin/lrelease-qt4

.if !defined(WITHOUT_NLS)
QT_COMPONENTS+=	linguist_build
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's,/usr/.*/aqemu,${DATADIR},' ${WRKSRC}/main.cpp

do-configure:
.if !defined(WITHOUT_NLS)
	cd ${WRKSRC} && ${QT_LRELEASE} ${QMAKE_PRO}
.endif
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKE_ARGS}

post-configure:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; s|^CXX .*|CXX=${CXX}|; s|^LINK .*|LINK=${CXX}|'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/AQEMU ${PREFIX}/bin/aqemu
	${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/menu_data/aqemu.desktop ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/menu_data/aqemu_*.png ${PREFIX}/share/pixmaps
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} os_icons ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} os_templates ${DATADIR}
.if !defined(WITHOUT_NLS)
	${INSTALL_DATA} ${WRKSRC}/*.qm ${DATADIR}
.endif

.include <bsd.port.mk>
