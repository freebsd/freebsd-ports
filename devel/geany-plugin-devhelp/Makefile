# $FreeBSD$

PORTNAME=	geany-plugin-devhelp
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

LIB_DEPENDS=	libwnck-1.so:x11-toolkits/libwnck \
		libwebkitgtk-1.0.so:www/webkit-gtk2

USE_GNOME=	gconf2

# Workaround for 9.x which doesn't have zlib.pc
LIBS=		-lz

post-patch:
	${REINPLACE_CMD} -e 's,zlib,,g' \
		${WRKSRC}/configure

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
