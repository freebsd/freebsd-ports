# New ports collection makefile for:	autotrace
# Date created:		12 April 2001
# Whom:			KANOU Hiroki <kanou@mil.allnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	autotrace
PORTVERSION=	0.31.1
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kanou@khdd.net
COMMENT=	Convert bitmap to vector graphics

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		ming.4:${PORTSDIR}/graphics/ming \
		Magick.10:${PORTSDIR}/graphics/ImageMagick \
		pstoedit.0:${PORTSDIR}/graphics/pstoedit

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/ming"
USE_XLIB=	yes

MAN1=		autotrace.1

pre-patch:
	@${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
