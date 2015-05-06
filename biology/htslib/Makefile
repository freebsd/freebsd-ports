# Created by: Reed A. Cartwright <cartwright@asu.edu>
# $FreeBSD$

PORTNAME=	htslib
PORTVERSION=	1.2.1
CATEGORIES=	biology devel

MAINTAINER=	cartwright@asu.edu
COMMENT=	C library for high-throughput sequencing data formats

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	samtools

USES=		gmake
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=yes

MAKE_ENV=	INSTALL_LIB="${INSTALL_LIB}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DIR="${MKDIR}"

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} -e 's|@PORTVERSION@|${PORTVERSION}|g' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
