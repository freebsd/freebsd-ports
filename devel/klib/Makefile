PORTNAME=	klib
DISTVERSION=	g20250105
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Standalone and lightweight C library
WWW=		http://attractivechaos.github.io/klib \
		https://github.com/attractivechaos/klib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	check>0:devel/check

USE_GITHUB=	yes
GH_ACCOUNT=	attractivechaos
GH_TAGNAME=	ba6b352

NO_BUILD=	yes
NO_ARCH=	yes

PORTSCOUT=	ignore:1 # only invalid tags like 'spawn-final' are present

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.h ${WRKSRC}/*.c ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} cpp ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
