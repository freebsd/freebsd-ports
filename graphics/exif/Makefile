# New ports collection makefile for:	exif
# Date created:				May 02 2005
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	exif
PORTVERSION=	0.6.20
CATEGORIES=	graphics
MASTER_SITES=	SF/lib${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Command line utility to read and manipulate EXIF data

LIB_DEPENDS=	exif.12:${PORTSDIR}/graphics/libexif \
		popt.0:${PORTSDIR}/devel/popt

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls --without-libiconv-prefix
CONFIGURE_ENV+=		POPT_CFLAGS=-I${PREFIX}/include POPT_LIBS="-L${PREFIX}/lib -lpopt"
PLIST_SUB+=	NLS="@comment "
.else
USE_ICONV=	yes
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

MAN1=		exif.1

.include <bsd.port.mk>
