# New ports collection makefile for:   pfstmo
# Date created:        Fri Jun  1 16:13:32 UTC 2007
# Whom:                argv[0] (Iouri V. Ivliev)
#
# $FreeBSD$

PORTNAME=	pfstmo
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/pfstools/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ii@any.com.ru
COMMENT=	Tone mapping operators

LIB_DEPENDS=	pfs-1.2:${PORTSDIR}/graphics/pfstools

PFS_CPPFLAGS=	-I${LOCALBASE}/include
PFS_LDFLAGS=	-L${LOCALBASE}/lib

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PFS_CPPFLAGS}" \
		LDFLAGS="${PFS_LDFLAGS}"
USE_GMAKE=	yes

MAN1=		pfstmo_pattanaik00.1 \
		pfstmo_reinhard05.1 \
		pfstmo_reinhard02.1 \
		pfstmo_durand02.1 \
		pfstmo_drago03.1 \
		pfstmo_mantiuk06.1 \
		pfstmo_fattal02.1

.include <bsd.port.pre.mk>

.if defined(WITH_FFTW3F)
LIB_DEPENDS+=	fftw3f.5:${PORTSDIR}/math/fftw3-float
.endif

.include <bsd.port.post.mk>
