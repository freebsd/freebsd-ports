# $FreeBSD$

PORTNAME=	timewarrior
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Track time from the command line

LICENSE=	MIT

USES=		cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	GothenburgBitFactory
GH_TUPLE=	GothenburgBitFactory:libshared:0d4e31d:libshared/src/libshared
CMAKE_ARGS+=	-DTIMEW_DOCDIR=${DOCSDIR}

.include <bsd.port.mk>
