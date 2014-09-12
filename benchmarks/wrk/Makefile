# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wrk
PORTVERSION=	3.1.1
CATEGORIES=	benchmarks www
MASTER_SITES=	https://github.com/wg/wrk/archive/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	The modern HTTP benchmarking tool

LICENSE=	APACHE20

LIB_DEPENDS+=	libluajit-5.1.so:${PORTSDIR}/lang/luajit
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		gmake
CFLAGS+=	-std=c99 -D_DECLARE_C99_LDBL_MATH

PLIST_FILES=	bin/wrk

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
