# New ports collection makefile for:	autotrace
# Date created:		12 April 2001
# Whom:			KANOU Hiroki <kanou@mil.allnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	autotrace
PORTVERSION=	0.31.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kanou@khdd.net
COMMENT=	Convert bitmap to vector graphics

LIB_DEPENDS=	jbig.1:${PORTSDIR}/graphics/jbigkit \
		df.1:${PORTSDIR}/science/hdf \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		ming.3:${PORTSDIR}/graphics/ming \
		wmf.2:${PORTSDIR}/graphics/libwmf \
		Magick.7:${PORTSDIR}/graphics/ImageMagick \
		pstoedit.0:${PORTSDIR}/graphics/pstoedit
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

INSTALLS_SHLIB=	yes
USE_INC_LIBTOOL_VER=13
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/ming"
USE_XLIB=	yes
USE_REINPLACE=	yes

MAN1=		autotrace.1

pre-patch:
	@${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
