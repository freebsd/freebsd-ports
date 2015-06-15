# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cqrlog
PORTVERSION=	1.9.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio logging application

LICENSE=	GPLv2

BUILD_DEPENDS=	lazbuild:${PORTSDIR}/editors/lazarus
LIB_DEPENDS=	libhamlib.so:${PORTSDIR}/comms/hamlib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GITHUB=	yes
GH_ACCOUNT=	ok2cqr

WANT_GNOME=	yes
ALL_TARGET=	${PORTNAME}

LAZARUS_VER=	1.4.0
LAZARUS_DIR=	${LOCALBASE}/share/lazarus-${LAZARUS_VER}

OPTIONS_SINGLE=		LCL
OPTIONS_SINGLE_LCL=	GTK2 QT4
OPTIONS_DEFAULT=	GTK2

GTK2_USE=	fpc=gtk2 gnome=gtk20
GTK2_BUILD_DEPENDS=	${LAZARUS_DIR}/lcl/units/${BUILDNAME}/gtk2/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-gtk2
GTK2_MAKE_ARGS=	PLATFORM=gtk2

QT4_USE=	fpc=yes
QT4_LIB_DEPENDS=	libQt4Pas.so:${PORTSDIR}/x11-toolkits/qt4pas
QT4_BUILD_DEPENDS=	${LAZARUS_DIR}/lcl/units/${BUILDNAME}/qt/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-qt
QT4_MAKE_ARGS=	PLATFORM=qt

post-patch:
	@${SED} -e s!%%LOCALBASE%%!${LOCALBASE}!g \
		-e s!%%MAKE_CMD%%!${MAKE_CMD}!g \
		-e s!%%LAZARUSDIR%%!${LAZARUS_DIR}!g \
		${FILESDIR}/environmentoptions.xml.in \
		> ${WRKSRC}/environmentoptions.xml
	${REINPLACE_CMD} -e s!%%LOCALBASE%%!${LOCALBASE}!g \
		${WRKSRC}/src/dData.pas ${WRKSRC}/src/dUtils.pas \
		${WRKSRC}/src/fLoTWExport.pas ${WRKSRC}/src/fPreferences.pas \
		${WRKSRC}/src/fRotControl.pas ${WRKSRC}/src/fTRXControl.pas \
		${WRKSRC}/src/fGrayline.pas
	${REINPLACE_CMD} -e s!%%PREFIX%%!${PREFIX}!g \
		${WRKSRC}/src/dData.pas ${WRKSRC}/src/fGrayline.pas
	${REINPLACE_CMD} -e s!%%LAZARUSDIR%%!${LAZARUS_DIR}!g \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
