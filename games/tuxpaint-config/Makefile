# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	tuxpaint-config
PORTVERSION=	0.0.13
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/tuxpaint/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical tool to change TuxPaint settings

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/docs/COPYING.txt

LIB_DEPENDS=	libpaper.so:print/libpaper \
		libfltk.so:x11-toolkits/fltk
RUN_DEPENDS=	tuxpaint:games/tuxpaint

USES=		gettext gmake
MAKE_ARGS=	PREFIX="${PREFIX}" \
		MAN_PREFIX="${MANPREFIX}/man" \
		GNOME_PREFIX="${PREFIX}" \
		CFLAGS="${CXXFLAGS} ${CPPFLAGS}" \
		ARCH_LINKS="${LDFLAGS}"
INSTALL_TARGET=	install-bin install-data install-man install-gettext \
		install-doc install-gnome
MAKE_JOBS_UNSAFE=yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
