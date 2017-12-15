# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	libpbl
PORTVERSION=	1.04.04
CATEGORIES=	databases
MASTER_SITES=	http://www.mission-base.com/peter/source/
DISTNAME=	pbl_${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Peter Graf's Program Base Library

LICENSE=	LGPL21+

MAKEFILE=	makefile
TEST_TARGET=	test

BROKEN_armv6=	Fails to build: cannot compile pblPerform.c
BROKEN_armv7=	Fails to build: cannot compile pblPerform.c
BROKEN_mips=	Fails to build: cannot compile pblPerform.c

WRKSRC=		${WRKDIR}/${DISTNAME}/src

PLIST_FILES=	include/pbl.h \
		lib/libpbl.a
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

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
