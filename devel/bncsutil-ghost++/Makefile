# Created by: <ports@c0decafe.net>
# $FreeBSD$

PORTNAME=	bncsutil
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=	-ghost++
DISTNAME=	${PROJECTHOST}_${PROJECTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility library for Battle.net clients in C++

LICENSE=	APACHE20

LIB_DEPENDS=	libgmp.so:math/gmp

PROJECTHOST=	ghostplusplus
PROJECTVERSION=	17.1

USES=		dos2unix gmake zip
WRKSRC=		${WRKDIR}/ghost/bncsutil/src/bncsutil
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libbncsutil.so

.include <bsd.port.mk>
