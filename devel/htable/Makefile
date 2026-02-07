PORTNAME=	htable
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	LOCAL/culot

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight implementation of hash tables in C
WWW=		http://culot.org/public/Code/htable.html

LICENSE=	BSD2CLAUSE

USES=		gmake
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	include/htable.h \
		share/man/man3/htable.3.gz

NO_BUILD=	yes
TEST_TARGET=	test
TEST_WRKSRC=	${WRKSRC}/tst

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/htable.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/src/htable.3 ${STAGEDIR}${PREFIX}/share/man/man3

.include <bsd.port.mk>
