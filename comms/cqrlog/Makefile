# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cqrlog
PORTVERSION=	1.8.2
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.cqrlog.com/files/cqrlog_${PORTVERSION}/ \
		LOCAL/shurd
DISTNAME=	${PORTNAME}_${PORTVERSION}.src

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio logging application

LICENSE=	GPLv2

BUILD_DEPENDS=	lazbuild:${PORTSDIR}/editors/lazarus
LIB_DEPENDS=	libhamlib.so:${PORTSDIR}/comms/hamlib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_FPC=	yes
WANT_GNOME=	yes
ALL_TARGET=	${PORTNAME}

LAZARUS_VER=    1.2.6
LAZARUS_DIR=    ${LOCALBASE}/share/lazarus-${LAZARUS_VER}

OPTIONS_SINGLE=		LCL
OPTIONS_SINGLE_LCL=	GTK2 QT4
OPTIONS_DEFAULT=	GTK2

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_FPC+=	gtk2
USE_GNOME=	gtk20
LCL_PLATFORM=	gtk2
BUILD_DEPENDS+=	${LAZARUS_DIR}/lcl/units/${BUILDNAME}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-gtk2
.endif

.if ${PORT_OPTIONS:MQT4}
LIB_DEPENDS+=	libQt4Pas.so:${PORTSDIR}/x11-toolkits/qt4pas
LCL_PLATFORM=	qt
BUILD_DEPENDS+=	${LAZARUS_DIR}/lcl/units/${BUILDNAME}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-qt
.endif

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
		-e s!%%LCL_PLATFORM%%!${LCL_PLATFORM}!g \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>
