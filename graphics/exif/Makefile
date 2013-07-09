# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exif
PORTVERSION=	0.6.20
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/lib${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line utility to read and manipulate EXIF data

LIB_DEPENDS=	exif.12:${PORTSDIR}/graphics/libexif \
		popt.0:${PORTSDIR}/devel/popt

USES=		pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ENV+=		POPT_CFLAGS=-I${LOCALBASE}/include POPT_LIBS="-L${LOCALBASE}/lib -lpopt"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext iconv
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls --without-libiconv-prefix
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=		exif.1

.include <bsd.port.mk>
