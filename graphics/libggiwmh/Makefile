# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libggiwmh
PORTVERSION=	0.3.2
PORTREVISION=	2
CATEGORIES=	graphics devel
MASTER_SITES=	SF/ggi/misc/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Libggi extension, wmh stands for Window Manager Hints

LICENSE=	MIT

LIB_DEPENDS=	ggi:${PORTSDIR}/graphics/libggi

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

LDFLAGS+=	${PTHREAD_LIBS}

MAN3=		ggiWmhIconify.3 \
		ggiWmhInit.3 \
		ggiWmhMove.3 \
		ggiWmhSetTitle.3 \
		ggiWmhZOrder.3
MAN7=		libggiwmh.7
MLINKS=		ggiWmhIconify.3 ggiWmhMoveIcon.3 \
		- ggiWmhSetIconTitle.3 \
		ggiWmhInit.3 ggiWmhAttach.3 \
		- ggiWmhDetach.3 - ggiWmhExit.3 \
		ggiWmhMove.3 ggiWmhAllowResize.3 \
		- ggiWmhGetPos.3 - ggiWmhGetSize.3 \
		- ggiWmhMaximize.3 - ggiWmhResize.3

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=--enable-x --with-x
USE_XORG=	x11
PLIST_SUB+=	XWMH=""
.else
CONFIGURE_ARGS+=--disable-x --without-x
PLIST_SUB+=	XWMH="@comment "
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/libggiwmh.conf ${PREFIX}/etc/ggi/libggiwmh.conf.dist

.include <bsd.port.mk>
