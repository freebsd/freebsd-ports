# New ports collection makefile for:	py-pyzmq
# Date created:				2011-01-10
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyzmq
PORTVERSION=	2.1.1
CATEGORIES=	devel net
MASTER_SITES=	http://cloud.github.com/downloads/zeromq/pyzmq/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Python bindings for ZeroMQ

LIB_DEPENDS=	zmq.1:${PORTSDIR}/devel/zmq

LICENSE=	LGPL3
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

pre-configure:
	@${SED} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/setup.cfg.template > \
		${WRKSRC}/setup.cfg

.include <bsd.port.post.mk>
