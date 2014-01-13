# Created by: Evan Sarmiento <bsdports@wayfair.com>
# $FreeBSD$

PORTNAME=	carbon
PORTVERSION=	0.9.12
CATEGORIES=	databases python
MASTER_SITES=	https://github.com/graphite-project/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bsdports@wayfair.com
COMMENT=	Backend storage application for graphite

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}txamqp>=0.3:${PORTSDIR}/net/py-txamqp \
		${PYTHON_PKGNAMEPREFIX}whisper>=0.9.10:${PORTSDIR}/databases/py-whisper

USE_PYTHON=	2
USE_PYDISTUTILS=	yes
USES=		twisted:run
FETCH_ARGS=	-o ${DISTNAME}${EXTRACT_SUFX}
USE_RC_SUBR=	carbon

NO_STAGE=	yes
.include <bsd.port.mk>
