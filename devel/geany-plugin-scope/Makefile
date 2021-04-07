PORTNAME=	geany-plugin-scope
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

gtk3_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
			libgnutls.so:security/gnutls

USES=		gnome xorg

USE_XORG=	x11 xext

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"

.if ${FLAVOR} == gtk3
USE_GNOME+=	vte3
.else
USE_GNOME+=	vte
.endif

.include <bsd.port.mk>
