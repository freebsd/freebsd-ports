# New ports collection makefile for:	bwbasic
# Date created:		16 Jan 1997
# Whom:			msmith@gsoft.com.au
#
# $FreeBSD$
#

PORTNAME=	bwbasic
PORTVERSION=	2.50
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/version%20${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Bywater Basic interpreter

USE_ZIP=	yes
USE_DOS2UNIX=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}
MAKE_ARGS=	CFLAGS="${CFLAGS} -ansi"

post-patch:
	${CHMOD} a+x ${WRKDIR}/configure

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/bwbasic.doc ${DOCSDIR}
	${CP} -r ${WRKSRC}/bwbtest ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
