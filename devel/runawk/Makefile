# New ports collection makefile for:	runawk
# Date created:				30 May 2010
# Whom:					Mikolaj Golub <to.my.trociny@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	runawk
PORTVERSION=	0.21.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	to.my.trociny@gmail.com
COMMENT=	Wrapper for AWK interpreter to write standalone programs in AWK

MAN1=		runawk.1
MANCOMPRESSED=	yes

MAKE_ENV+=	MANDIR=${PREFIX}/man/man NO_OBJ=yes

PORTDOCS=	ChangeLog NEWS README TODO

pre-install:
	@${MKDIR} ${PREFIX}/share/runawk

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
