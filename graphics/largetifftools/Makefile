# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	largetifftools
PORTVERSION=	1.3.10
CATEGORIES=	graphics
MASTER_SITES=	https://www.imnc.in2p3.fr/pagesperso/deroulers/software/largetifftools/download/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Process very large TIFF files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png

GNU_CONFIGURE=	yes
USES=		autoreconf jpeg localbase:ldconfig tar:bzip2

.include <bsd.port.mk>
