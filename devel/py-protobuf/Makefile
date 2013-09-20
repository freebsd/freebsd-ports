# Created by: vanilla@
# $FreeBSD$

PORTNAME=	protobuf
PORTVERSION=	2.5.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Google protobuf Python Client Library

BUILD_DEPENDS=	protoc:${PORTSDIR}/devel/protobuf

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/python
PROJECTHOST=	protobuf
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
pre-build:
	@${MKDIR} ${WRKSRC}/google/protobuf/compiler

.include <bsd.port.mk>
