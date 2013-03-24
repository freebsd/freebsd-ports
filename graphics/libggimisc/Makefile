# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libggimisc
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	SF/ggi/lowlevel/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Libggi extension providing support for hard to categorize features

LICENSE=	MIT

LIB_DEPENDS=	ggi:${PORTSDIR}/graphics/libggi

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

LDFLAGS+=	${PTHREAD_LIBS}

MAN3=		ggiGetRayPos.3 \
		ggiSetSplitline.3 \
		ggiWaitRayPos.3
MAN7=		libggimisc.7

OPTIONS_DEFINE=	SVGALIB

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSVGALIB}
CONFIGURE_ARGS+=--enable-svgalib
LIB_DEPENDS+=	vga:${PORTSDIR}/graphics/svgalib
PLIST_SUB+=	WITH_SVGALIB=""
.else
CONFIGURE_ARGS+=--disable-svgalib
PLIST_SUB+=	WITH_SVGALIB="@comment "
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/libggimisc.conf ${PREFIX}/etc/ggi/libggimisc.conf.dist

.include <bsd.port.mk>
