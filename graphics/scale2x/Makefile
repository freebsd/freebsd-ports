# Ports collection makefile for:	scale2x
# Date created:			2006/12/01
# Whom:				chinsan
#
# $FreeBSD$
#

PORTNAME=	scale2x
PORTVERSION=	2.4
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time graphics effect able to increase the size of small bitmaps

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes

MAN1=		scalex.1 scalerx.1
PLIST_FILES=	bin/scalex bin/scalerx

CPPFLAGS+=	`libpng15-config --I_opts`
LDFLAGS+=	`libpng15-config --L_opts`

post-patch:
	${REINPLACE_CMD} -e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${WRKSRC}/file.c

.include <bsd.port.mk>
