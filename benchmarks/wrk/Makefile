# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wrk
PORTVERSION=	4.0.1
CATEGORIES=	benchmarks www
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Modern HTTP benchmarking tool

LICENSE=	APACHE20

LIB_DEPENDS=	libluajit-5.1.so:${PORTSDIR}/lang/luajit

USE_GITHUB=	yes
GH_ACCOUNT=	wg

USES=		gmake
USE_OPENSSL=	yes
CFLAGS+=	-std=c99 -D_DECLARE_C99_LDBL_MATH

PLIST_FILES=	bin/wrk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
