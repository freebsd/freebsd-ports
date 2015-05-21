# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	liblzma
PORTVERSION=	0.5.3
PORTREVISION=	4
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Python binding for the LZMA compression library

LICENSE=	LGPL3

USES=		pkgconfig python tar:bzip2
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e 's/pc_cflags = .*/pc_cflags = ""/' \
		-e 's/pc_libs = .*/pc_libs = "-llzma"/' ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lzma.so

.include <bsd.port.mk>
