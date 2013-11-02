# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	swfmill
PORTVERSION=	0.3.3
CATEGORIES=	graphics
MASTER_SITES=	http://swfmill.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to generate or decompile Adobe Flash SWF files

LICENSE=	GPLv2

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2

USES=		iconv gmake pkgconfig
USE_GNOME=	libxml2 libxslt
USE_AUTOTOOLS=	libtool

PLIST_FILES=	bin/swfmill

.include <bsd.port.mk>
