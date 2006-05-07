# ex:ts=8
# New ports collection makefile for:	libAfterImage
# Date created:			Oct 7, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libafterimage
PORTVERSION=	1.07
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	afterstep
DISTNAME=	libAfterImage-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic imaging library originally designed for AfterStep

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--disable-staticlibs --enable-sharedlibs \
		--without-builtin-ungif --without-afterbase \
		--with-x
INSTALLS_SHLIB=	yes

MAN1=	ascompose.1x

.include <bsd.port.pre.mk>

.if ${MACHINE_CPU:Mmmx}
CONFIGURE_ARGS+=	--enable-mmx-optimization
.else
CONFIGURE_ARGS+=	--disable-mmx-optimization
.endif

post-extract:
	@${LN} -sf ${WRKSRC} ${WRKDIR}/libAfterImage

post-patch:
	@${REINPLACE_CMD} -e 's| malloc\.h | |g ; \
		 s|-lgif|-lungif|g ; \
		 s|CFLAGS="-O3"||g ; \
		 s| -rdynamic||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|; ;|;|g' ${WRKSRC}/asimagexml.c

post-install:
	${INSTALL_MAN} ${WRKSRC}/apps/ascompose.man \
		${MANPREFIX}/man/man1/ascompose.1x

.include <bsd.port.post.mk>
