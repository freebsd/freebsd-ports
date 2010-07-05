# New ports collection makefile for:	zathura
# Date created:				29 June 2010
# Whom:					Quentin Stievenart <acieroid@awesom.eu>
#
# $FreeBSD$
#

PORTNAME=	zathura
PORTVERSION=	0.0.7
CATEGORIES=	graphics print
MASTER_SITES=	http://pwmt.org/zathura/download/

MAINTAINER=	acieroid@awesom.eu
COMMENT=	Customizable lightweight pdf viewer

LIB_DEPENDS=	poppler-glib.4:${PORTSDIR}/graphics/poppler-gtk	\
		cairo.2:${PORTSDIR}/graphics/cairo

USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20
MAN1=	zathura.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/zathura

post-patch:
	@${REINPLACE_CMD} -e 's|man1|man/man1|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
