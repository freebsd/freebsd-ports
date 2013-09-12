# Created by: Iouri V. Ivliev
# $FreeBSD$

PORTNAME=	pfscalibration
PORTVERSION=	1.3
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/pfstools/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ii@any.com.ru
COMMENT=	Photometric calibration of cameras and recovery HDR images from the set of LDR exposures

PFS_CPPFLAGS=	-I${LOCALBASE}/include
PFS_LDFLAGS=	-L${LOCALBASE}/lib

USES=		gmake pkgconfig shebangfix perl5
GNU_CONFIGURE=	yes
CPPFLAGS+=	${PFS_CPPFLAGS}
LDFLAGS+=	${PFS_LDFLAGS}

LIB_DEPENDS=	pfs-1.2:${PORTSDIR}/graphics/pfstools

MAN1=		jpeg2hdrgen.1 \
		dcraw2hdrgen.1 \
		pfsinhdrgen.1 \
		pfshdrcalibrate.1

SHEBANG_FILES=	src/dcraw2hdrgen src/jpeg2hdrgen
bash_CMD=	${SH}

.include <bsd.port.mk>
