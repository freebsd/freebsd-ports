# New ports collection makefile for:	bsdar
# Date created:				18 Jan 2008
# Whom:					Gabor Kovesdan <gabor@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	ar
PORTVERSION=	20080302
CATEGORIES=	archivers
MASTER_SITES=	http://people.freebsd.org/~kaiw/distfiles/
PKGNAMEPREFIX=	bsd-
EXTRACT_SUFX=	.tgz

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	BSD-licensed replacement of the ar utility

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/ar bin/ranlib
MAN1=		ar.1 ranlib.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700055 || ${OSVERSION} >= 900012
IGNORE=		does not compile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ar ${PREFIX}/bin/ar
	${LN} -s ${PREFIX}/bin/ar ${PREFIX}/bin/ranlib
	${INSTALL_MAN} ${WRKSRC}/ar.1 ${MAN1PREFIX}/man/man1/ar.1
	${INSTALL_MAN} ${WRKSRC}/ar.1 ${MAN1PREFIX}/man/man1/ranlib.1

.include <bsd.port.post.mk>
