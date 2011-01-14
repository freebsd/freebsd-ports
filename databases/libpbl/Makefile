# New ports collection makefile for:	databases/libpbl
# Date Created:				2 Jan 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	libpbl
PORTVERSION=	1.04
CATEGORIES=	databases
MASTER_SITES=	http://www.mission-base.com/peter/source/
DISTNAME=	pbl_${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Peter Graf's Program Base Library

BROKEN=		checksum mismatch

MAKEFILE=	makefile
PLIST_FILES=	lib/libpbl.a include/pbl.h
MAKE_JOBS_SAFE=	yes

.ifndef(NOPORTDOCS)
PORTDOCS=	*
.endif

post-extract:
	@${REINPLACE_CMD} -e 's/=  -Wall -O3/+=  -Wall -Werror/' \
		-e 's/^CC=/CC?=/' -e '/^.rm -f/d' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's/%d/%zd/' -e 's/(int)size/size/' ${WRKSRC}/pbl.c
	@${REINPLACE_CMD} -e 's/dir\.h/dirent\.h/' ${WRKSRC}/pbl.h
	@${REINPLACE_CMD} -e 's/malloc\.h/stdlib\.h/' \
		${WRKSRC}/*.c

do-install:
	@${INSTALL_DATA} ${WRKSRC}/libpbl.a ${LOCALBASE}/lib
	@${INSTALL_DATA} ${WRKSRC}/pbl.h ${LOCALBASE}/include

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
.endif

post-build test regression-test check:
	${MAKE} -C ${WRKSRC} test

.include <bsd.port.mk>
