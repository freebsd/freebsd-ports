# New ports collection makefile for:	databases/libpbl
# Date Created:				2 Jan 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	libpbl
PORTVERSION=	1.03
CATEGORIES=	databases
MASTER_SITES=	http://mission.base.com/peter/source/
DISTNAME=	pbl_1_03

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Peter Graf's Program Base Library

ALL_TARGET=	libpbl.a
MAKEFILE=	makefile
PLIST_FILES=	lib/libpbl.a include/pbl.h

.ifndef(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

post-extract:
	@${REINPLACE_CMD} -e 's/=  -Wall -O3/+=  -Wall/' \
		-e 's/^CC=/CC?=/' ${WRKSRC}/makefile
.if ${OSVERSION} >= 500000
	@${REINPLACE_CMD} -e 's/%d/%zd/' ${WRKSRC}/pbl.c
.endif
	@${REINPLACE_CMD} -e 's/dir\.h/dirent\.h/' ${WRKSRC}/pbl.h
	@${REINPLACE_CMD} -e 's/malloc\.h/stdlib\.h/' \
		${WRKSRC}/pbl.c ${WRKSRC}/pblhash.c

do-install:
	@${INSTALL_DATA} ${WRKSRC}/libpbl.a ${LOCALBASE}/lib
	@${INSTALL_DATA} ${WRKSRC}/pbl.h ${LOCALBASE}/include

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
