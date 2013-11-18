# Created by: <ports@c0decafe.net>
# $FreeBSD$

PORTNAME=	bncsutil
PORTVERSION=	1.3.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMESUFFIX=	-ghost++
EXTRACT_SUFX=	.zip
DISTNAME=	${PROJECTHOST}_${PROJECTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility library for Battle.net clients in C++

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp

PROJECTHOST=	ghostplusplus
PROJECTVERSION=	17.1

USES=		dos2unix gmake
WRKSRC=		${WRKDIR}/ghost/bncsutil/src/bncsutil

USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
