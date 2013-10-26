# Created by: h2
# $FreeBSD$

PORTNAME=	seqan
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://ftp.seqan.de/releases/

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	C++ Sequence Analysis Library

LICENSE=	BSD GPLv3
LICENSE_COMB=	multi

LICENSE_FILE_BSD=${WRKSRC}/seqan/LICENSE
LICENSE_FILE_GPLv3=${WRKSRC}/apps/LICENSE

USE_ZIP=	yes

USES=		cmake:outsource
CMAKE_SOURCE_PATH=${WRKSRC}/cmake
USE_PYTHON_BUILD=yes
MAKE_JOB_SAFE=	yes

SUB_FILES=	pkg-message
PKG_MESSAGE=	${WRKDIR}/pkg-message

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == i386
# triggers internal error in system gcc
USE_GCC=	yes
.endif

# unsafe workaround because FreeBSD lacks logl and expl
# see "BUGS" in `man 3 math`
post-patch:
	@${REINPLACE_CMD} -e 's|expl|exp|g' ${WRKSRC}/apps/snp_store/snp_store.h
	@${REINPLACE_CMD} -e 's|logl|log|g' ${WRKSRC}/apps/snp_store/snp_store.h

post-install:
	@${CAT} ${PKG_MESSAGE}

.include <bsd.port.post.mk>
