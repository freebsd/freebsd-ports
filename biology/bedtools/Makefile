# $FreeBSD$

PORTNAME=	bedtools
DISTVERSIONPREFIX=	v
DISTVERSION=	2.27.1
PORTREVISION=	2
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Toolset for genome set arithmetic such as intersect, union

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gmake python
USE_GITHUB=	yes
GH_ACCOUNT=	arq5x
GH_PROJECT=	bedtools2

pre-build:
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|@\$$(CXX)|$$(CXX)|g' \
		${WRKSRC}/*/Makefile \
		${WRKSRC}/*/*/Makefile \
		${WRKSRC}/*/*/*/Makefile \
		${WRKSRC}/*/*/*/*/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bedtools

.include <bsd.port.mk>
