# Created by: Tim Cas <ports@stdrand.com>
# $FreeBSD$

PORTNAME=	ChipmunkPhysics
PORTVERSION=	6.1.3
CATEGORIES=	devel
MASTER_SITES=	http://chipmunk-physics.net/release/Chipmunk-6.x/ \
		http://files.libsiege.org/chipmunk/
DISTNAME=	Chipmunk-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@stdrand.com
COMMENT=	2D physics engine written in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_CMAKE=	yes
CMAKE_ARGS=	-DBUILD_DEMOS=OFF
MAKE_JOBS_SAFE=	yes

USE_LDCONFIG=	yes

.include <bsd.port.mk>
