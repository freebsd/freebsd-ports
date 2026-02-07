PORTNAME=	tuxpaint-config
PORTVERSION=	0.0.25
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/tuxpaint/${PORTNAME}/${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Graphical tool to change TuxPaint settings
WWW=		https://www.tuxpaint.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/docs/COPYING.txt

LIB_DEPENDS=	libpaper.so:print/libpaper \
		libfltk.so:x11-toolkits/fltk \
		libunibreak.so:textproc/libunibreak \
		libSDL2_Pango.so:x11-toolkits/sdl2_pango
RUN_DEPENDS=	tuxpaint:games/tuxpaint

USES=		gettext gmake pkgconfig
MAKE_ARGS=	PREFIX="${PREFIX}" \
		MAN_PREFIX="${PREFIX}/share/man" \
		GNOME_PREFIX="${PREFIX}" \
		CFLAGS="${CXXFLAGS} ${CPPFLAGS}" \
		ARCH_LINKS="${LDFLAGS}"
INSTALL_TARGET=	install-bin install-data install-man install-gettext \
		install-doc
MAKE_JOBS_UNSAFE=yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
