# $FreeBSD$

PORTNAME=	rem
PORTVERSION=	0.4.7
CATEGORIES=	audio devel
MASTER_SITES=	http://www.creytiv.com/pub/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Library for real-time audio and video processing

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/docs/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/re/re.mk:audio/re
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	(cd ${WRKSRC}/include && \
	    ${COPYTREE_SHARE} \*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME})
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib${PORTNAME}.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
