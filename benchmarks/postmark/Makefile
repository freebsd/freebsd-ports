# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	postmark
PORTVERSION=	1.53
CATEGORIES=	benchmarks
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NetApps file system benchmark

LICENSE=	ART10 LGPL21
LICENSE_COMB=	multi

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		postmark.1
PLIST_FILES=	sbin/postmark

NO_STAGE=	yes
do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o postmark postmark-${PORTVERSION}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/postmark ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/postmark.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
