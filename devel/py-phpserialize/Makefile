# Created by: Jui-Nan Lin <jnlin@freebsd.cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	phpserialize
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	devel lang www python
MASTER_SITES=	http://www.hurring.com/scott/code/python/serialize/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PHPSerialize_v${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jnlin@freebsd.cs.nctu.edu.tw
COMMENT=	Python implementation of PHP's native serialize() and unserialize()

WRKSRC=		${WRKDIR}/v${PORTVERSION}

USES=		python
USE_PYTHON=	distutils autoplist

post-extract:
	${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|g' ${FILESDIR}/setup.py \
		> ${WRKSRC}/setup.py

.include <bsd.port.mk>
