# ex:ts=8
# Ports collection makefile for:  postmark
# Date created:			  Sat Sep 18, 1999
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	postmark
PORTVERSION=	1.5
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.netapp.com/ftp/  \
		http://dl.droso.net/ports/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NetApps file system benchmark

NO_WRKSUBDIR=	yes
PLIST_FILES=	sbin/postmark

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o postmark ${DISTFILES})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/postmark ${PREFIX}/sbin

.include <bsd.port.mk>
