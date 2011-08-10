# New ports collection makefile for:	tuxpaint-config
# Date created:				28 Nov 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	tuxpaint-config
PORTVERSION=	0.0.12
CATEGORIES=	games
MASTER_SITES=	SF/tuxpaint/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical tool to change TuxPaint settings

LIB_DEPENDS=	paper.2:${PORTSDIR}/print/libpaper \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk
RUN_DEPENDS=	tuxpaint:${PORTSDIR}/games/tuxpaint

USE_GETTEXT=	yes
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

.include <bsd.port.mk>
