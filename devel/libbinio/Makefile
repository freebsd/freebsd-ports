# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	libbinio
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Binary I/O stream class library

LICENSE=	LGPL21

USES=		pathfix libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CFLAGS+=	${CPPFLAGS}
CXXFLAGS+=	${CPPFLAGS}

INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS\ =\).*|\1 src|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
