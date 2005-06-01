# New ports collection makefile for:	jasper
# Date created:				6 November 1994
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jasper
PORTVERSION=	1.701.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.ece.uvic.ca/~mdadams/jasper/software/ \
		${MASTER_SITE_IMAGEMAGICK}
MASTER_SITE_SUBDIR=	ImageMagick/delegates

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An implementation of the codec specified in the JPEG-2000 standard

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_ZIP=	yes
USE_GNOME=	gnometarget lthack
USE_LIBTOOL_VER=15
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-shared --enable-static
INSTALLS_SHLIB=	yes

MASTER_SITE_IMAGEMAGICK=	\
	ftp://ftp.imagemagick.org/pub/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/&,}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
