# New ports collection makefile for:	mupdf
# Date created:		2009-08-07
# Whom:			Martin Dieringer <martin.dieringer@gmx.de>
#
# $FreeBSD$

PORTNAME=	mupdf
PORTVERSION=	0.7
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.mupdf.com/download/

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Lightweight PDF viewer and toolkit

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		jbig2dec.0:${PORTSDIR}/graphics/jbig2dec \
		openjpeg.2:${PORTSDIR}/graphics/openjpeg

USE_GMAKE=	yes
MAKE_ARGS+=	build=release prefix=${PREFIX} verbose=1
USE_XORG=	x11 xext
USE_GNOME=	pkgconfig
USE_GCC=	4.2+

MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's#\(PDF.*_EXE=.*DIR./\)#\1mu_#g' \
		-e '/install:/,/^$$/ { /-d/d; }' \
		-e '/install.*bin$$/s/install/$$(BSD_INSTALL_PROGRAM)/' \
		-e '/install.*lib$$/s/install/$$(BSD_INSTALL_PROGRAM)/' \
		-e '/install.*include$$/s/install/$$(BSD_INSTALL_DATA)/' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's/LAGS :=/LAGS +=/g' \
		-e 's/-O2//' -e 's/-g//' \
		-e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/Makerules

.include <bsd.port.mk>
