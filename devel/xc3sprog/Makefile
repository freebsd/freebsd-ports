# $FreeBSD$

PORTNAME=	xc3sprog
PORTVERSION=	r769
CATEGORIES=	devel
MASTER_SITES=	http://opsec.eu/src/xc3sprog/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free programmer for Xilinx Spartan S3E Starter Kit

LIB_DEPENDS=	libftdi.so:${PORTSDIR}/devel/libftdi
BUILD_DEPENDS=	${LOCALBASE}/bin/cmake:${PORTSDIR}/devel/cmake
RUN_DEPENDS=	${LOCALBASE}/sbin/fxload:${PORTSDIR}/misc/fxload

USES=		tar:xz
ALL_TARGET=	xc3sprog

PLIST_FILES=	bin/xc3sprog

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/cmake .

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xc3sprog ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 800069)
BROKEN=	doesn't build on FreeBSD prior libusb(8) integration to base system
.endif

.include <bsd.port.post.mk>
