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

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e "s,mkdir rmdir,mkdir mkstemp rmdir," \
		${WRKSRC}/configure

.include <bsd.port.mk>
