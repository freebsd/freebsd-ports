# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	cmake-fedora
PORTVERSION=	2.9.2
DISTVERSIONSUFFIX=	-modules-only
CATEGORIES=	devel
MASTER_SITES=	https://releases.pagure.org/cmake-fedora/

MAINTAINER=	buganini@gmail.com
COMMENT=	Set of cmake modules for fedora developers

LICENSE=	BSD3CLAUSE

WRKSRC=		${WRKDIR}/Modules
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cmake/Modules
	${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${PREFIX}/share/cmake/Modules

.include <bsd.port.mk>
