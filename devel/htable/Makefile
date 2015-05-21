# Created by: Frederic Culot <frederic@culot.org>
# $FreeBSD$

PORTNAME=	htable
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	LOCAL/culot

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Lightweight implementation of hash tables in C

USES=		gmake
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	include/htable.h \
		man/man3/htable.3.gz

NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/htable.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/src/htable.3 ${STAGEDIR}${MAN3PREFIX}/man/man3

regression-test:
	cd ${WRKSRC}/tst && ${MAKE_CMD} test

.include <bsd.port.mk>
