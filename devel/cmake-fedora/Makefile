# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	cmake-fedora
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	https://fedorahosted.org/releases/c/m/cmake-fedora/
DISTNAME=	${PORTNAME}-${PORTVERSION}-modules-only

MAINTAINER=	buganini@gmail.com
COMMENT=	Set of cmake modules for fedora developers

LICENSE=	BSD

WRKSRC=		${WRKDIR}/Modules
NO_BUILD=	yes

NO_STAGE=	yes
post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	${MKDIR} ${PREFIX}/share/cmake/Modules
	cd ${WRKSRC}/ && \
		${INSTALL_DATA} * ${PREFIX}/share/cmake/Modules

.include <bsd.port.mk>
