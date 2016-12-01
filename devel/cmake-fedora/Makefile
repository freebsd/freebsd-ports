# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	cmake-fedora
PORTVERSION=	2.3.4
CATEGORIES=	devel
MASTER_SITES=	https://fedorahosted.org/releases/c/m/cmake-fedora/
DISTNAME=	${PORTNAME}-${PORTVERSION}-modules-only

MAINTAINER=	buganini@gmail.com
COMMENT=	Set of cmake modules for fedora developers

LICENSE=	BSD3CLAUSE

WRKSRC=		${WRKDIR}/Modules
NO_BUILD=	yes
REINPLACE_ARGS=	-i ''

post-patch:
	@${REINPLACE_CMD} -e 's|-printf .*$$|-exec basename {} ";"|' \
		${WRKSRC}/ManageTranslation.cmake

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cmake/Modules
	cd ${WRKSRC}/ && \
		${INSTALL_DATA} * ${STAGEDIR}${PREFIX}/share/cmake/Modules

.include <bsd.port.mk>
