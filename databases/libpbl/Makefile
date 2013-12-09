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

WRKSRC=		${WRKDIR}/${DISTNAME}/src

PLIST_FILES=lib/libpbl.a include/pbl.h
PORTDOCS=	*

post-extract:
	@${REINPLACE_CMD} -e 's/=  -Wall -O3/+=  -Wall -Werror/' \
		-e 's/^CC=/CC?=/' -e '/^.rm -f/d' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's/%d/%zd/' -e 's/(int)size/size/' ${WRKSRC}/pbl.c
	@${REINPLACE_CMD} -e 's/dir\.h/dirent\.h/' ${WRKSRC}/pbl.h
	@${REINPLACE_CMD} -e 's/malloc\.h/stdlib\.h/' \
		${WRKSRC}/*.c

do-install:
	${INSTALL_DATA} ${WRKSRC}/libpbl.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/pbl.h ${STAGEDIR}${PREFIX}/include/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}/

test regression-test check:
	${MAKE} -C ${WRKSRC} test

.include <bsd.port.mk>
