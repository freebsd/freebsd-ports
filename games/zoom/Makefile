# Created by: Jan Stocker <Jan.Stocker@t-online.de>
# $FreeBSD$

PORTNAME=	zoom
PORTVERSION=	1.1.5
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.logicalshift.co.uk/unix/zoom/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Z-Interpreter for X with full V6 support

LICENSE=	LGPL21

LIB_DEPENDS=	libt1.so:devel/t1lib \
		libpng.so:graphics/png

USES=		gmake perl5 xorg
GNU_CONFIGURE=	yes
USE_CSTD=	gnu89
USE_XORG=	xft

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/zoom
PORTDATA=	zoomrc
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	(cd ${WRKSRC}/manual && ${COPYTREE_SHARE} \
		. ${STAGEDIR}${DOCSDIR} "! -name Makefile \
		! -name Makefile.am ! -name Makefile.in")

.include <bsd.port.mk>
