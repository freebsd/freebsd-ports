PORTNAME=	libusbsio
PORTVERSION=	2.1.11
CATEGORIES=	comms

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Native C port for NXP libusbsio library
WWW=		https://www.nxp.com/design/software/development-software/library-for-windows-macos-and-ubuntu-linux:LIBUSBSIO

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libhidapi.so:comms/hidapi \
		libudev.so:devel/libudev-devd

USES=		gmake localbase:ldflags pkgconfig

MAKEFILE=	makefile

USE_GITHUB=	yes
GH_ACCOUNT=	monwarez
GH_TAGNAME=	8577280966ee91cab606df5b0c64889be71ce7b9

PLIST_FILES=	lib/${PORTNAME}.a lib/${PORTNAME}.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/bin/${OPSYS:tl}_${ARCH}/${PORTNAME}.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/bin/${OPSYS:tl}_${ARCH}/${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
