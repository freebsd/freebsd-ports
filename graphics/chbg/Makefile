# Created by: Peter Jones <p@dancris.com>
# $FreeBSD$

PORTNAME=	chbg
PORTVERSION=	1.5
PORTREVISION=	14
CATEGORIES=	graphics gnome
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Change Background Picture with time period

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

USES=		gmake gettext pathfix
USE_GNOME=	gdkpixbuf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gnome

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		's|^guint argc|gint argc|' ${WRKSRC}/src/chbg.c

.include <bsd.port.mk>
