# $FreeBSD$

PORTNAME=		libheif
DISTVERSIONPREFIX=	v
DISTVERSION=		1.3.2
CATEGORIES=		graphics

MAINTAINER=		me@sebastiansteinmetz.ch
COMMENT=		Libheif is an ISO/IEC 23008-12:2017 HEIF file format de- and encoder

LICENSE=		LGPL3+
LICENSE_FILE=		${WRKSRC}/COPYING

BROKEN_FreeBSD_10=	encoder_fuzzer.cc:84:5: error: use of undeclared identifier 'free'

LIB_DEPENDS=		libde265.so:multimedia/libde265
LIB_DEPENDS+=		libx265.so:multimedia/x265
LIB_DEPENDS+=		libpng16.so:graphics/png

USES=			autoreconf libtool pkgconfig shared-mime-info \
			shebangfix
USE_GITHUB=		yes
GH_ACCOUNT=		strukturag
GH_PROJECT=		libheif

GNU_CONFIGURE=		yes

SHEBANG_GLOB=		*.sh

USE_LDCONFIG=		yes

.include <bsd.port.mk>
