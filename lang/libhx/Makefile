# Created by: Sylvio Cesar <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libHX
PORTVERSION=	3.14.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
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

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's| -lrt||g' ${WRKSRC}/src/Makefile.in
.if empty(PORT_OPTIONS:MDOCS)
	${REINPLACE_CMD} -e 's|libHX_Documentation.pdf||' \
	   ${WRKSRC}/doc/Makefile.in ${WRKSRC}/doc/Makefile.am
.endif

.include <bsd.port.mk>
