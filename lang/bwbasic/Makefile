# New ports collection makefile for:	bwbasic
# Date created:		16 Jan 1997
# Whom:			msmith@gsoft.com.au
#
# $FreeBSD$
#

PORTNAME=	bwbasic
PORTVERSION=	2.20p2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.rahul.net/pub2/rhn/www/files/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	msmith@FreeBSD.org

GNU_CONFIGURE=	yes
WRKTOP=		${WRKDIR}/${DISTNAME}
WRKSUBDIR=	bwbasic-2.20
WRKSRC=		${WRKTOP}/${WRKSUBDIR}

pre-patch:
	cd ${WRKTOP} && ${MV} bwb-2.20-patch01/* ${WRKSUBDIR}
	cd ${WRKTOP} && ${MV} bwb-2.20-patch02/* ${WRKSUBDIR}

# This puts the documentation in ${PREFIX}/share/bwbasic, and the
# test programs in ${PREFIX}/share/bwbasic/bwbtest.

post-install:
	-${MKDIR} ${PREFIX}/share/bwbasic
	${CP} ${WRKSRC}/bwbasic.doc ${PREFIX}/share/bwbasic/
	${CP} -r ${WRKSRC}/bwbtest ${PREFIX}/share/bwbasic/

.include <bsd.port.mk>
