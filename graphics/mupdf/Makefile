# New ports collection makefile for:	mupdf
# Date created:		2009-08-07
# Whom:			Martin Dieringer <martin.dieringer@gmx.de>
#
# $FreeBSD$

PORTNAME=	mupdf
PORTVERSION=	0.6
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.mupdf.com/download/source/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Lightweight PDF viewer and toolkit

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		jbig2dec.0:${PORTSDIR}/graphics/jbig2dec \
		openjpeg.2:${PORTSDIR}/graphics/openjpeg

USE_GMAKE=	yes
MAKE_ARGS+=	build=release prefix=${PREFIX} verbose=true
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_XORG=	x11 xext
USE_GNOME=	pkgconfig
USE_GCC=	4.2+

MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} 's/LAGS :=/LAGS +=/g' ${WRKSRC}/Makerules
	@${REINPLACE_CMD} 's/Linux/FreeBSD/g' ${WRKSRC}/Makerules
	@${REINPLACE_CMD} 's/CC = .*/CC = ${CC}/g' ${WRKSRC}/Makerules
	@${REINPLACE_CMD} 's#\(PDF.*_EXE=.*DIR./\)#\1mu_#g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
