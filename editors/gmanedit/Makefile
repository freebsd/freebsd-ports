PORTNAME=	gmanedit
PORTVERSION=	0.4.2
PORTREVISION=	9
CATEGORIES=	editors gnome
MASTER_SITES=	SF/${PORTNAME}2/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GNOME manpages editor
WWW=		https://sourceforge.net/projects/gmanedit2/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Upstream last release was in 2008
EXPIRATION_DATE=	2024-03-31

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
	libfreetype.so:print/freetype2 \
	libharfbuzz.so:print/harfbuzz

USES=		gettext gmake gnome localbase:ldflags pathfix pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk20

GNU_CONFIGURE=	yes

LDFLAGS+=	-lz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

post-patch:
	@${REINPLACE_CMD} -e '/<argz\.h>/d' ${WRKSRC}/src/callbacks.c

.include <bsd.port.post.mk>
