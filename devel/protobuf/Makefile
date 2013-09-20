# Created by: vanilla
# $FreeBSD$

PORTNAME=	protobuf
PORTVERSION=	2.5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A data interchange format library

USE_GMAKE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		pathfix pkgconfig
ONLY_FOR_ARCHS=	i386 amd64

tests: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

NO_STAGE=	yes
.include <bsd.port.mk>
