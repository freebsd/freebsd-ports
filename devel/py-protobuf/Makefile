# New ports collection makefile for:	py-protobuf
# Date created:				May 27 2009
# Whom:					vanilla@
#
# $FreeBSD$
#

PORTNAME=	protobuf
PORTVERSION=	2.1.0
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

.include <bsd.port.mk>
