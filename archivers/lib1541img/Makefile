# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	lib1541img
PORTVERSION=	1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	archivers devel emulators

MAINTAINER=	felix@palmen-it.de
COMMENT=	Library for handling commodore 1541 disk images

LICENSE=	BSD2CLAUSE

USES=		compiler:c11 gmake

USE_GITHUB=	yes
GH_PROJECT=	zimk:zimk
GH_ACCOUNT=	excess-c64 Zirias:zimk
GH_TAGNAME=	31500ca:zimk

USE_LDCONFIG=	yes
MAKE_ARGS=	pkgconfigdir=${LOCALBASE}/libdata/pkgconfig \
		1541img_DOCDIR=${LOCALBASE}/share/doc/lib1541img \
		V=1
ALL_TARGET=	strip

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen>0:devel/doxygen
DOXYGEN_ALL_TARGET=	html

post-extract:
	@${MV} ${WRKSRC_zimk}/* ${WRKSRC}/zimk/

.include <bsd.port.mk>
