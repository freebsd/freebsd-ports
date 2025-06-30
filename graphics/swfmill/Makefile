PORTNAME=	swfmill
PORTVERSION=	0.3.6
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://swfmill.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to generate or decompile Adobe Flash SWF files
WWW=		https://swfmill.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error

USES=		compiler:c++11-lang dos2unix gmake gnome iconv libtool \
		pkgconfig
USE_GNOME=	libxml2 libxslt
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
DOS2UNIX_FILES=	src/swft/swft_import_ttf.cpp

PLIST_FILES=	bin/swfmill

.include <bsd.port.mk>
