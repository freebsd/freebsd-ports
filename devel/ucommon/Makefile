# Created by: gahr
# $FreeBSD$

PORTNAME=	ucommon
PORTVERSION=	6.0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	commoncpp

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Very lightweight C++ design pattern library

LICENSE=	LGPL3

USES=	pathfix pkgconfig cmake:outsource
CMAKE_ARGS+=	-DBUILD_TESTING:BOOL=ON \
    		-DINSTALL_BINDIR:STRING=bin/${PORTNAME}
USE_LDCONFIG=	yes

MAN1=	args.1 car.1 commoncpp-config.1 mdsum.1 pdetach.1 \
	scrub-files.1 sockaddr.1 ucommon-config.1 zerofill.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

regression-test: build
	cd ${BUILD_WRKSRC}/test && ${MAKE} test

.include <bsd.port.post.mk>
