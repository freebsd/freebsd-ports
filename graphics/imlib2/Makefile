# New ports collection makefile for:	imlib2
# Date created:		16 Oct 2000
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	imlib2
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	The next generation graphic library for enlightenment package

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		ltdl.1:${PORTSDIR}/devel/libtool \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_FREETYPE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/freetype1 \
			  -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CONFIGURE_ARGS=	--enable-mmx
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|\@localbase\@|${LOCALBASE}|g' ${WRKSRC}/imlib2-config

.include <bsd.port.post.mk>
