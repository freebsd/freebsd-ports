# New ports collection makefile for:   ecgi
# Date created:        13 February 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ecgi
PORTVERSION=	0.6.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/libe/libecgi
DISTNAME=	lib${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for the creation of CGI-based Web applications

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_REINPLACE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
CFLAGS+=	"-fPIC"

HEADER_FILES=	ecgi.h ecgitk.h include/memfile.h

pre-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' ${WRKSRC}/src/memfile.c

do-install:
	${INSTALL_DATA} ${WRKSRC}/libecgi.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libecgi.so ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/html2h/html2h ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/include/ecgi
.for file in ${HEADER_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include/ecgi
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ecgitut.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
