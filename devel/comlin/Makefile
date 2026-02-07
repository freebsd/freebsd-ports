PORTNAME=	comlin # fork of github.com/antirez/linenoise (port devel/linenoise)
DISTVERSION=	g20240315
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Small self-contained alternative to readline and libedit
WWW=		https://github.com/drobilla/comlin

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		meson
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	drobilla
GH_TAGNAME=	4d13650

MESON_ARGS=	-Ddocs=disabled

PLIST_FILES=	include/comlin.h \
		lib/libcomlin.so \
		lib/libcomlin.so.0 \
		lib/libcomlin.so.0.0.1 \
		libdata/pkgconfig/comlin.pc

.include <bsd.port.mk>
