PORTNAME=	timewarrior
PORTVERSION=	1.4.2
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Track time from the command line

LICENSE=	MIT

USES=		cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	GothenburgBitFactory
GH_TUPLE=	GothenburgBitFactory:libshared:b8b5796:libshared/src/libshared
CMAKE_ARGS+=	-DTIMEW_DOCDIR=${DOCSDIR}

.include <bsd.port.mk>
