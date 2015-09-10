# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	stepcode
PORTVERSION=	0.8
DISTVERSIONPREFIX=	v
CATEGORIES=	cad

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Generates C++ and Python from ISO10303 files

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes

USE_LDCONFIG=	yes

USES=		cmake:outsource compiler:c++11-lang
CMAKE_ARGS+=	-DSC_INSTALL_PREFIX=${PREFIX} \
		-DSC_BUILD_TYPE=Release

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/schema_scanner
	@(cd ${STAGEDIR}${PREFIX} ; \
		${FIND} include \( -type f -or -type l \) | ${SORT} >> ${TMPPLIST})

.include <bsd.port.mk>
