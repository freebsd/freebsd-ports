# Created by: Glenn Johnson
# $FreeBSD$

PORTNAME=	libproplist
PORTVERSION=	0.10.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	TUCOWS/gnome/dev
DISTNAME=	libPropList-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Property library for gnome and Window Maker

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e "s,mkdir rmdir,mkdir mkstemp rmdir," \
		${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libPropList.so

.include <bsd.port.mk>
