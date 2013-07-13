# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wrk
PORTVERSION=	2.2.2
CATEGORIES=	benchmarks www
MASTER_SITES=	https://github.com/wg/wrk/archive/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	The modern HTTP benchmarking tool

LICENSE=	AL2

FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes
CFLAGS+=	-std=c99 -D_DECLARE_C99_LDBL_MATH

PLIST_FILES=	bin/wrk

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not link on FreeBSD 7.x
.endif

post-patch:
	@${REINPLACE_CMD} '1d;2s/-lpthread/${PTHREAD_LIBS}/' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
