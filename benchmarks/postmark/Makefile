# ex:ts=8
# Ports collection makefile for:  postmark
# Date created:			  Sat Sep 18, 1999
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

DISTNAME=	postmark-1_11
PKGNAME=	postmark-1.11
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.netapp.com/ftp/  \
		http://www.taronga.com/~nick/files/
EXTRACT_SUFX=	.c

MAINTAINER=	obrien@FreeBSD.org

NO_WRKSUBDIR=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o postmark ${DISTFILES})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/postmark ${PREFIX}/sbin

.include <bsd.port.mk>
