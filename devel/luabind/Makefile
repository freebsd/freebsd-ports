# New ports collection makefile for:	luabind
# Date created:		06 Jun 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	luabind
PORTVERSION=	0.7
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library that helps you create bindings between C++ and Lua

BUILD_DEPENDS=	${LOCALBASE}/include/boost/python/detail/is_xxx.hpp:${PORTSDIR}/devel/boost-python
RUN_DEPENDS=	${LOCALBASE}/include/boost/python/detail/is_xxx.hpp:${PORTSDIR}/devel/boost-python

USE_ZIP=	yes
USE_LUA=	5.0
USE_GMAKE=	yes

MAKE_ENV=	BOOST_ROOT="${LOCALBASE}/include"

WRKSRC=		${WRKDIR}/${PORTNAME}

BUILD_WRKSRC=	${WRKSRC}/src

MAKEFILE=	makefile

PORTDOCS=	*

post-patch:
	${MKDIR} ${WRKSRC}/lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/libluabind.a ${PREFIX}/lib
	(cd ${WRKSRC} && ${COPYTREE_SHARE} luabind ${PREFIX}/include)

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.mk>
