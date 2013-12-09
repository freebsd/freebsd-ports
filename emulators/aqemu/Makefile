# $FreeBSD$

PORTNAME=	aqemu
PORTVERSION=	0.8.2
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:S,.0$,,}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt 4 based Qemu frontend

LIB_DEPENDS=	libvncclient.so:${PORTSDIR}/net/libvncserver

USE_BZIP2=	yes
USE_QT4=	gui qtestlib xml qmake_build uic_build moc_build rcc_build \
		linguist_build
USES=		cmake
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S,.0$,,}

.include <bsd.port.mk>
