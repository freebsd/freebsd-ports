# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	swfmill
PORTVERSION=	0.3.2
CATEGORIES=	graphics
MASTER_SITES=	http://swfmill.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to generate or decompile Adobe Flash SWF files

LICENSE=	GPLv2

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2

USES=		pkgconfig iconv
USE_GNOME=	libxml2 libxslt
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool

PLIST_FILES=	bin/swfmill

.include <bsd.port.mk>
