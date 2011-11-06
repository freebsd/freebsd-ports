# New ports collection makefile for:	zoom
# Date created:				May 07 2003
# Whom:					Jan Stocker <Jan.Stocker@t-online.de>
#
# $FreeBSD$
#

PORTNAME=	zoom
PORTVERSION=	1.1.5
CATEGORIES=	games
MASTER_SITES=	http://www.logicalshift.co.uk/unix/zoom/ \
		http://mirror.4bit.ws/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Z-Interpreter for X with full V6 support

LIB_DEPENDS=	t1.5:${PORTSDIR}/devel/t1lib \
		png.6:${PORTSDIR}/graphics/png

USE_CSTD=	gnu89
USE_PERL5=	yes
USE_XORG=	xft
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/zoom %%DATADIR%%/zoomrc
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.mk>
