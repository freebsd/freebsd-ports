# Created by: Iouri V. Ivliev
# $FreeBSD$

PORTNAME=	pfscalibration
PORTVERSION=	1.4
CATEGORIES=	graphics
MASTER_SITES=	SF/pfstools/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ii@any.com.ru
COMMENT=	Photometric calibration of cameras and recovery HDR images from the set of LDR exposures

PFS_CPPFLAGS=	-I${LOCALBASE}/include
PFS_LDFLAGS=	-L${LOCALBASE}/lib

USES=		gmake pkgconfig shebangfix perl5
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${PFS_CPPFLAGS}" \
		LDFLAGS="${PFS_LDFLAGS}"

USE_PERL5=	run

SHEBANG_FILES=	src/dcraw2hdrgen src/jpeg2hdrgen src/pfsinhdrgen
bash_CMD=	${SH}

LIB_DEPENDS=	libpfs-1.2.so:graphics/pfstools

.include <bsd.port.mk>
