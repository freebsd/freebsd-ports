# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	libpbl
PORTVERSION=	1.04.04
CATEGORIES=	databases
MASTER_SITES=	http://www.mission-base.com/peter/source/
DISTNAME=	pbl_${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Peter Graf's Program Base Library

MAKEFILE=	makefile
PLIST_FILES=	lib/libpbl.a include/pbl.h

WRKSRC=		${WRKDIR}/${DISTNAME}/src

.ifndef(NOPORTDOCS)
PORTDOCS=	*
.endif

NO_STAGE=	yes
post-extract:
	@${REINPLACE_CMD} -e 's/=  -Wall -O3/+=  -Wall -Werror/' \
		-e 's/^CC=/CC?=/' -e '/^.rm -f/d' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's/%d/%zd/' -e 's/(int)size/size/' ${WRKSRC}/pbl.c
	@${REINPLACE_CMD} -e 's/dir\.h/dirent\.h/' ${WRKSRC}/pbl.h
	@${REINPLACE_CMD} -e 's/malloc\.h/stdlib\.h/' \
		${WRKSRC}/*.c

do-install:
	${MKDIR} ${PREFIX}/lib ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libpbl.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/pbl.h ${PREFIX}/include/
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}/
.endif

post-build test regression-test check:
	${MAKE} -C ${WRKSRC} test

.include <bsd.port.mk>
