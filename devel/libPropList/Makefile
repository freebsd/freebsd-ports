# Created by: Glenn Johnson
# $FreeBSD$

PORTNAME=	libproplist
PORTVERSION=	0.10.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://distfiles.macports.org/libproplist/
DISTNAME=	libPropList-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Property library for gnome and Window Maker

GNU_CONFIGURE=	yes
USES=		libtool
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e "s,mkdir rmdir,mkdir mkstemp rmdir," \
		${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libPropList.so

.include <bsd.port.mk>
