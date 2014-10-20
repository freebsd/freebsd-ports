# Created by: Peter Haight <peterh@sapros.com>
# $FreeBSD$

PORTNAME=	scons
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	gavin@16degrees.com.au
COMMENT=	Build tool alternative to make

LICENSE=	MIT

RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USES=		python:2
USE_PYTHON=	distutils autoplist

PLIST_SUB+=	SCONS_VER=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} \
		-e 's,distutils\.command\.install$$,setuptools\.command\.install,' \
		-e 's,distutils\.command\.install\.,setuptools\.command\.install\.,' \
		${WRKSRC}/setup.py
	@${FIND} ${WRKSRC} -name \*.orig -delete

.include <bsd.port.mk>
