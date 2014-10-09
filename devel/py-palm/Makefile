# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	palm
PORTVERSION=	0.1.7
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Protobufs Are Lightweight Messages

LICENSE=	BSD2CLAUSE

USES=		python
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_LIBDIR}/site-packages/${PORTNAME}/${PORTNAME}.so

.include <bsd.port.mk>
