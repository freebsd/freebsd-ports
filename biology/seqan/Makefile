# Created by: h2
# $FreeBSD$

PORTNAME=	seqan
PORTVERSION=	1.3.1
PORTREVISION=	3
CATEGORIES=	biology
MASTER_SITES=	http://ftp.seqan.de/releases/

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	C++ Sequence Analysis Library

LICENSE=	BSD3CLAUSE GPLv3
LICENSE_COMB=	multi

LICENSE_FILE_BSD=${WRKSRC}/seqan/LICENSE
LICENSE_FILE_GPLv3=${WRKSRC}/apps/LICENSE

USES=		cmake:outsource zip
CMAKE_SOURCE_PATH=${WRKSRC}/cmake
USE_PYTHON_BUILD=yes
MAKE_JOB_SAFE=	yes

SUB_FILES=	pkg-message
PKG_MESSAGE=	${WRKDIR}/pkg-message

USE_GCC=	yes

# unsafe workaround because FreeBSD lacks logl and expl
# see "BUGS" in `man 3 math`
post-patch:
	@${REINPLACE_CMD} -e 's|expl|exp|g' ${WRKSRC}/apps/snp_store/snp_store.h
	@${REINPLACE_CMD} -e 's|logl|log|g' ${WRKSRC}/apps/snp_store/snp_store.h

.include <bsd.port.mk>
