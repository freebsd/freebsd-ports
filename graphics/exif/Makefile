# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exif
PORTVERSION=	0.6.21
CATEGORIES=	graphics
MASTER_SITES=	SF/lib${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command line utility to read and manipulate EXIF data

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexif.so:graphics/libexif \
		libpopt.so:devel/popt

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

CPE_VENDOR=	curtis_galloway
GNU_CONFIGURE=	yes
USES=		cpe gmake localbase pkgconfig

NLS_CONFIGURE_ON=	--enable-nls ${ICONV_CONFIGURE_ARG}
NLS_CONFIGURE_OFF=	--disable-nls --without-libiconv-prefix
NLS_USES=		gettext iconv

.include <bsd.port.mk>
