# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avro
PORTVERSION=	1.7.4
CATEGORIES=	devel
MASTER_SITES=	http://www.sai.msu.su/apache/${PORTNAME}/${PORTNAME}-${PORTVERSION}/ \
		APACHE
MASTER_SITE_SUBDIR=	${PORTNAME}/stable
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Data serialization system for python

USE_PYDISTUTILS=	yes
USE_PYTHON=		yes
PYDISTUTILS_AUTOPLIST=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/lang/py

pre-configure:
	${REINPLACE_CMD} 's|@AVRO_VERSION@|${PORTVERSION}|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
