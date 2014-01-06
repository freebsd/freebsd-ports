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

PLIST_FILES=	sbin/postmark \
		man/man1/postmark.1.gz

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o postmark postmark-${PORTVERSION}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/postmark ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/postmark.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
