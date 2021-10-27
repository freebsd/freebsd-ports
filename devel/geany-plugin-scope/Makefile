PORTNAME=	geany-plugin-scope
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libgnutls.so:security/gnutls

USES=		gnome xorg
USE_XORG=	x11 xext
USE_GNOME=	vte3

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
