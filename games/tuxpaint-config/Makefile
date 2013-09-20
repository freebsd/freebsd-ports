# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	tuxpaint-config
PORTVERSION=	0.0.12
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/tuxpaint/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical tool to change TuxPaint settings

LIB_DEPENDS=	paper.2:${PORTSDIR}/print/libpaper \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk
RUN_DEPENDS=	tuxpaint:${PORTSDIR}/games/tuxpaint

USES=		gettext
USE_GMAKE=	yes
MAKE_ARGS=	PREFIX="${PREFIX}" \
		MAN_PREFIX="${MANPREFIX}/man" \
		X11_ICON_PREFIX="${PREFIX}/share/pixmaps/" \
		CFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		ARCH_LINKS="-L${LOCALBASE}/lib -lintl"

MANCOMPRESSED=	yes
MAN1=		tuxpaint-config.1

.if defined(NOPORTDOCS)
INSTALL_TARGET=	install-bin install-data install-man install-gettext
.else
INSTALL_TARGET=	install-bin install-data install-man install-gettext install-doc
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
