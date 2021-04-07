PORTNAME=	geany-plugin-utilslib
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

OPTIONS_DEFINE=	DOCS

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"

.if ${FLAVOR} == gtk2
USES+=		xorg
USE_GNOME+=	vte
USE_XORG+=	x11 xext
.endif

.include <bsd.port.mk>
