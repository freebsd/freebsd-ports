# New ports collection makefile for:	libhx
# Date created:		2009-06-20
# Whom:			Sylvio Cesar <sylvio@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libHX
PORTVERSION=	3.2
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Library C with some additional C++ bindings available

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

USE_LDCONFIG=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:22

PORTDOCS=	libHX_Documentation.pdf

post-patch:
	${REINPLACE_CMD} -e 's| -lrt||g' ${WRKSRC}/src/Makefile.in

post-build:
	@${REINPLACE_CMD} -e 's|doc src|src|g' ${WRKSRC}/Makefile

post-install:
	(mv ${PREFIX}/lib/pkgconfig/libHX.pc ${PREFIX}/libdata/pkgconfig/libHX.pc)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
