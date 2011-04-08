# New ports collection makefile for:	mupdf
# Date created:		2009-08-07
# Whom:			Martin Dieringer <martin.dieringer@gmx.de>
#
# $FreeBSD$

PORTNAME=	mupdf
PORTVERSION=	0.8.15
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE \
		http://www.mupdf.com/download/

DISTFILES=	${PORTNAME}-${DISTVERSION}-source.tar.gz

MAINTAINER=	lichray@gmail.com
COMMENT=	Lightweight PDF viewer and toolkit

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		jbig2dec.0:${PORTSDIR}/graphics/jbig2dec \
		openjpeg.2:${PORTSDIR}/graphics/openjpeg

USE_GMAKE=	yes
MAKE_ARGS+=	build=release prefix=${PREFIX} verbose=1 MANDIR=${PREFIX}/man/man1 APPS_MAN="${MAN1:S@^@apps/man/@}" LIBDIR=${PREFIX}/lib
USE_XORG=	x11 xext
USE_GNOME=	pkgconfig
MAN1=		mupdf.1 mu_pdfclean.1 mu_pdfdraw.1 mu_pdfshow.1

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
	${REINPLACE_CMD} -e 's/-O2//' \
		-e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/Makerules

pre-install:	.SILENT
	find ${WRKSRC} -name pdf\*.1 -exec sh -c 'mv {} $$(dirname {})/mu_$$(basename {})' \;

.include <bsd.port.mk>
