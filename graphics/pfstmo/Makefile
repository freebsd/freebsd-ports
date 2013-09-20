# Created by: Iouri V. Ivliev
# $FreeBSD$

PORTNAME=	pfstmo
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/pfstools/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ii@any.com.ru
COMMENT=	Tone mapping operators

LIB_DEPENDS=	pfs-1.2:${PORTSDIR}/graphics/pfstools

PFS_CPPFLAGS=	-I${LOCALBASE}/include
PFS_LDFLAGS=	-L${LOCALBASE}/lib

USES=		pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	${PFS_CPPFLAGS}
LDFLAGS+=	${PFS_LDFLAGS}
USE_GMAKE=	yes

MAN1=		pfstmo_pattanaik00.1 \
		pfstmo_reinhard05.1 \
		pfstmo_reinhard02.1 \
		pfstmo_durand02.1 \
		pfstmo_drago03.1 \
		pfstmo_mantiuk06.1 \
		pfstmo_fattal02.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if defined(WITH_FFTW3F)
LIB_DEPENDS+=	fftw3f:${PORTSDIR}/math/fftw3-float
.endif

.include <bsd.port.post.mk>
