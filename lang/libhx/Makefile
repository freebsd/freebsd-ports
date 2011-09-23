# New ports collection makefile for:	libhx
# Date created:		2009-06-20
# Whom:			Sylvio Cesar <sylvio@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libHX
PORTVERSION=	3.10.1
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Library C with some additional C++ bindings available

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_XZ=		yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS+=--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

.if !defined(NOPORTDOCS)
PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:L}
.endif

MAN1=		hxdirstamp.1

post-patch:
	${REINPLACE_CMD} -e 's| -lrt||g' ${WRKSRC}/src/Makefile.in
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|libHX_Documentation.pdf||' \
	   ${WRKSRC}/doc/Makefile.in ${WRKSRC}/doc/Makefile.am
.endif

.include <bsd.port.mk>
