# New ports collection makefile for:   ecgi
# Date created:        13 February 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=       ecgi
PORTVERSION=	0.6.2
CATEGORIES=     devel
MASTER_SITES=   http://www.global-owl.com/ecgi/download/

MAINTAINER=	ports@freebsd.org

USE_GMAKE=	yes

INSTALLS_SHLIB=	yes

HEADER_FILES=	ecgi.h ecgitk.h include/memfile.h

pre-patch:
	@${PERL} -pi -e 's,<malloc.h>,<stdlib.h>,' ${WRKSRC}/src/memfile.c

do-install:
	@${INSTALL_DATA} ${WRKSRC}/libecgi.a ${PREFIX}/lib
	@${INSTALL_PROGRAM} ${WRKSRC}/libecgi.so ${PREFIX}/lib
	@${INSTALL_PROGRAM} ${WRKSRC}/html2h/html2h ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/include/ecgi
.for file in ${HEADER_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include/ecgi
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ecgi
	@${INSTALL_DATA} ${WRKSRC}/doc/ecgitut.txt ${PREFIX}/share/doc/ecgi
.endif

.include <bsd.port.mk>
