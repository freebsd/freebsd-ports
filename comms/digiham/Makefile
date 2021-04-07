PORTNAME=	digiham
DISTVERSION=	0.3.0
CATEGORIES=	comms hamradio

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Tools for decoding digital ham communication

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmbe.so:comms/mbelib

USES=		cmake
USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	jketterl
GH_PROJECT=	digiham

post-install:
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
