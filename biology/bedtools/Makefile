PORTNAME=		bedtools
DISTVERSIONPREFIX=	v
DISTVERSION=		2.31.0
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Toolset for genome set arithmetic such as intersect, union
WWW=		https://bedtools.readthedocs.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang gmake python
USE_GITHUB=	yes

GH_ACCOUNT=	arq5x
GH_PROJECT=	bedtools2

pre-configure:
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|g' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bedtools

do-test:
	(cd ${WRKSRC}/test && bash test.sh)

.include <bsd.port.mk>
