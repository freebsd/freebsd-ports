PORTNAME=	stepcode
PORTVERSION=	0.8.2
DISTVERSIONPREFIX=	v
CATEGORIES=	cad

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Generates C++ and Python from ISO10303 files
WWW=		https://github.com/stepcode/stepcode/wiki

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DSC_INSTALL_PREFIX=${PREFIX} \
		-DSC_BUILD_TYPE=Release

MANDIRS=	${PREFIX}/man

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/schema_scanner
	@(cd ${STAGEDIR}${PREFIX} ; \
		${FIND} include \( -type f -or -type l \) | ${SORT} >> ${TMPPLIST})

.include <bsd.port.mk>
