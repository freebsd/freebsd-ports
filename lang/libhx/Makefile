# Created by: Sylvio Cesar <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libHX
PORTVERSION=	3.22
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C/C++ library with common data structures and functions

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USES=		libtool tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:tl}

post-patch:
	${REINPLACE_CMD} -e 's| -lrt||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
