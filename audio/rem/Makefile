# $FreeBSD$

PORTNAME=	rem
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	audio devel
MASTER_SITES=	http://www.creytiv.com/pub/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Library for real-time audio and video processing

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/docs/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/re/re.mk:${PORTSDIR}/audio/re
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_LDCONFIG=	yes
USES=		gmake

do-install:
	${MKDIR} ${PREFIX}/include/${PORTNAME}
	(cd ${WRKSRC}/include && \
	    ${COPYTREE_SHARE} \*.h ${PREFIX}/include/${PORTNAME})
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.[sa]* ${PREFIX}/lib

.include <bsd.port.mk>
