# $FreeBSD$

PORTNAME=	lgi
PORTVERSION=	0.6.2
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	andreevmaxim@gmail.com
COMMENT=	Lua bindings to libraries using GObject-Introspection

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/pavouk-lgi-a4ad06c

USE_GITHUB=	yes
GH_ACCOUNT=	pavouk

USE_LUA=	5.1+
USE_GMAKE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include/${LUA_SUBDIR}

.include <bsd.port.mk>
