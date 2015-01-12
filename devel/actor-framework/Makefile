# Created by: vanilla@
# $FreeBSD$

PORTNAME=	actor-framework
PORTVERSION=	0.12.1
CATEGORIES=	devel net
MASTER_SITES=	GH

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	C++ actor framework

LICENSE=	BSD3CLAUSE

CXXFLAGS+=	-std=c++11
LDFLAGS+=	-pthread
USES=		compiler:c++11-lang cmake:outsource
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_COMMIT=	56ad470

.include <bsd.port.mk>
