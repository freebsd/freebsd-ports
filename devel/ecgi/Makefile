# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	ecgi
PORTVERSION=	0.6.3
CATEGORIES=	devel
MASTER_SITES=	https://BSDforge.com/projects/source/devel/ecgi/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Library for the creation of CGI-based Web applications

LICENSE=	BSD3CLAUSE

USES=		gmake tar:xz
PORTDOCS=	*
HEADER_FILES=	ecgi.h ecgitk.h include/memfile.h

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' ${WRKSRC}/src/memfile.c

do-install:
	${INSTALL_DATA} ${WRKSRC}/libecgi.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libecgi.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/html2h/html2h ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/ecgi
.for file in ${HEADER_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/include/ecgi
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ecgitut.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
