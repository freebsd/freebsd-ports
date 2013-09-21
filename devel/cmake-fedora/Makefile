# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	cmake-fedora
PORTVERSION=	1.0.5
CATEGORIES=	devel
MASTER_SITES=	https://fedorahosted.org/releases/c/m/cmake-fedora/
DISTNAME=	${PORTNAME}-${PORTVERSION}-modules-only

MAINTAINER=	buganini@gmail.com
COMMENT=	Set of cmake modules for fedora developers

LICENSE=	BSD

WRKSRC=		${WRKDIR}/Modules
NO_BUILD=	yes
NO_STAGE=	yes
REINPLACE_ARGS=	-i ''

post-patch:
	@${REINPLACE_CMD} -e 's|date --utc|date -u|' ${WRKSRC}/DateTimeFormat.cmake

do-install:
	${MKDIR} ${PREFIX}/share/cmake/Modules
	cd ${WRKSRC}/ && \
		${INSTALL_DATA} * ${PREFIX}/share/cmake/Modules

.include <bsd.port.mk>
