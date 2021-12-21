# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	librtprocess
PORTVERSION=	0.11.0
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Library for raw image processing

LICENSE=	GPLv3+

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	CarVac
USE_LDCONFIG=	yes

.if !defined(WITH_DEBUG)
CXXFLAGS+=	-DNDEBUG
.endif

.include <bsd.port.mk>
