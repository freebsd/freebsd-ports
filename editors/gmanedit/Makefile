PORTNAME=	gmanedit
PORTVERSION=	0.4.2
PORTREVISION=	10
CATEGORIES=	editors gnome
MASTER_SITES=	SF/${PORTNAME}2/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GNOME manpages editor
WWW=		https://sourceforge.net/projects/gmanedit2/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		gettext gmake gnome pkgconfig
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_GNOME=	cairo gdkpixbuf2 gtk20

LDFLAGS+=	-lz

post-patch:
	@${REINPLACE_CMD} -e '/-DGTK_DISABLE_DEPRECATED/d' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/<argz\.h>/d' ${WRKSRC}/src/callbacks.c

.include <bsd.port.mk>
