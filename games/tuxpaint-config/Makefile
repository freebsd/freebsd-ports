# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	tuxpaint-config
PORTVERSION=	0.0.12
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/tuxpaint/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical tool to change TuxPaint settings

LIB_DEPENDS=	libpaper.so:${PORTSDIR}/print/libpaper \
		libfltk.so:${PORTSDIR}/x11-toolkits/fltk
RUN_DEPENDS=	tuxpaint:${PORTSDIR}/games/tuxpaint

USES=		gettext gmake
MAKE_ARGS=	PREFIX="${PREFIX}" \
		MAN_PREFIX="${MANPREFIX}/man" \
		X11_ICON_PREFIX="${PREFIX}/share/pixmaps/" \
		CFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		ARCH_LINKS="-L${LOCALBASE}/lib -lintl"
INSTALL_TARGET=	install-bin install-data install-man install-gettext install-doc
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E 's,(BIN|DATA|DOC|LOCALE|MAN)_PREFIX),DESTDIR)$$(&,' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
