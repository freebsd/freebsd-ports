# New ports collection makefile for:	pbl
# Date created:				3. Jan 2006
# Whom:					johans
#
# $FreeBSD$

PORTNAME=	pbl
PORTVERSION=	1.03
CATEGORIES=	databases
MASTER_SITES=	http://mission.base.com/peter/source/ \
		ftp://ftp.stack.nl/pub/users/johans/pbl/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/}

MAINTAINER=	johans@stack.nl
COMMENT=	A highly portable database library

USE_REINPLACE=	yes

MAKEFILE=	makefile

PLIST_FILES=	lib/libpbl.a include/pbl.h bin/pblkfblockprint
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -E '/^(CC|CFLAGS)/d; s/-O2//' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's/malloc\.h/stdlib.h/' ${WRKSRC}/*.c
	@${REINPLACE_CMD} -e 's/sys\/dir\.h/dirent.h/' ${WRKSRC}/pbl.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/libpbl.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/pbl.h ${PREFIX}/include
	${INSTALL_PROGRAM} ${WRKSRC}/pblkfblockprint ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
