PORTNAME=	gammaray
PORTVERSION=	2.11.3
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Debugging tool for Qt-application
WWW=		https://www.kdab.com/development-resources/qt-tools/gammaray/

LICENSE=	GPLv2 BSD2CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE.GPL.txt
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE.BSD2.txt

LIB_DEPENDS=	libdwarf.so:devel/libdwarf \
		libelf.so:devel/libelf

USES=		cmake kde:5 pkgconfig qt:5

USE_QT=		3d concurrent core declarative designer gui help linguisttools \
		location network printsupport script scripttools svg uiplugin \
		webchannel widgets xml buildtools:build qdoc:build qmake:build
USE_KDE=	coreaddons syntaxhighlighting

USE_GITHUB=	yes
GH_ACCOUNT=	KDAB
GH_PROJECT=	GammaRay

CMAKE_OFF=	STACK_DETAILS_AUTO_DETECT
CMAKE_ON=	STACK_DETAILS_DWARF

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB=	WEBENGINE=""
USE_QT+=	webengine
.else
PLIST_SUB=	WEBENGINE="@comment "
.endif

PLIST_SUB+=	ARCH=${ARCH:S/amd64/x86_64/:S/i386/i686/:C/armv./arm/} \
		PORTMAJMIN=${PORTVERSION:C/(.*)\..*/\1/} \
		PORTVERSION=${PORTVERSION} \
		QTVER=${QT5_VERSION:C/\./_/:C/\..*//}

.include <bsd.port.mk>
