# $FreeBSD$

PORTNAME=	aqemu
PORTVERSION=	0.8.2
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:S,.0$,,}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt 4 based Qemu frontend

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvncclient.so:net/libvncserver

USE_QT4=	corelib gui network qtestlib xml linguisttools_build \
		moc_build qmake_build rcc_build uic_build
USES=		cmake tar:bzip2
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S,.0$,,}

.include <bsd.port.mk>
