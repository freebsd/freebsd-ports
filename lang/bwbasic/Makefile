# New ports collection makefile for:	bwbasic
# Date created:		16 Jan 1997
# Whom:			msmith@gsoft.com.au
#
# $FreeBSD$
#

PORTNAME=	bwbasic
PORTVERSION=	2.20p2
CATEGORIES=	lang
MASTER_SITES=	http://www.nicholson.com/rhn/files/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Bywater Basic interpreter

GNU_CONFIGURE=	yes
WRKTOP=		${WRKDIR}/${DISTNAME}
WRKSUBDIR=	bwbasic-2.20
WRKSRC=		${WRKTOP}/${WRKSUBDIR}
MAKE_ARGS=	CFLAGS="${CFLAGS} -ansi"

pre-patch:
	cd ${WRKTOP} && ${MV} bwb-2.20-patch01/* ${WRKSUBDIR}
	cd ${WRKTOP} && ${MV} bwb-2.20-patch02/* ${WRKSUBDIR}

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/bwbasic.doc ${DOCSDIR}
	${CP} -r ${WRKSRC}/bwbtest ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
