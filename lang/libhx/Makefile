# Created by: Sylvio Cesar <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libHX
PORTVERSION=	3.14.1
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	C/C++ library with common data structures and functions

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_XZ=		yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS+=--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig

.if !defined(NOPORTDOCS)
PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:L}
.endif

post-patch:
	${REINPLACE_CMD} -e 's| -lrt||g' ${WRKSRC}/src/Makefile.in
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|libHX_Documentation.pdf||' \
	   ${WRKSRC}/doc/Makefile.in ${WRKSRC}/doc/Makefile.am
.endif

.include <bsd.port.mk>
