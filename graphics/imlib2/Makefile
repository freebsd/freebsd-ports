# New ports collection makefile for:	imlib2
# Date created:		16 Oct 2000
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	imlib2
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	The next generation graphic library for enlightenment package

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2

USE_LIBLTDL=	yes
USE_LIBTOOL_VER=	15
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_AUTOCONF_VER=	259
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${PREFIX}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${PREFIX}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CONFIGURE_ARGS+=	--enable-mmx
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|lround|(long int)rint|g' ${WRKSRC}/src/lib/color_helpers.c

.include <bsd.port.post.mk>
