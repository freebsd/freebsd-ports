# ex:ts=8
# New ports collection makefile for:	libAfterImage
# Date created:			Oct 7, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libafterimage
PORTVERSION=	0.92
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	afterstep
DISTNAME=	libAfterImage-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic imaging library originally designed for AfterStep

LIB_DEPENDS=	AfterBase.0:${PORTSDIR}/devel/libafterbase \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--disable-staticlibs --enable-sharedlibs --with-builtin-xpm --with-x
INSTALLS_SHLIB=	yes
PLIST_SUB=	STATIC="@comment "

MAN1=	ascompose.1x
MAN3=	afterimage.3x ascmap.3x asfont.3x asimage.3x asvisual.3x blender.3x \
	export.3x import.3x transform.3x ximage.3x

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CONFIGURE_ARGS+=	--enable-mmx-optimization
.else
CONFIGURE_ARGS+=	--disable-mmx-optimization
.endif

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install.doc
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lgif|-lungif|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>|g'

.include <bsd.port.post.mk>
