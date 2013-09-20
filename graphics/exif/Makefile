# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exif
PORTVERSION=	0.6.21
CATEGORIES=	graphics
MASTER_SITES=	SF/lib${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command line utility to read and manipulate EXIF data

LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif \
		libpopt.so:${PORTSDIR}/devel/popt

OPTIONS_DEFINE=	NLS

CONFIGURE_ENV=	POPT_CFLAGS=-I${LOCALBASE}/include POPT_LIBS="-L${LOCALBASE}/lib -lpopt"
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=--enable-nls ${ICONV_CONFIGURE_ARG}
USES+=		gettext iconv
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls --without-libiconv-prefix
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=		exif.1

.include <bsd.port.mk>
