# Created by: Reed A. Cartwright <cartwright@asu.edu>
# $FreeBSD$

PORTNAME=	samtools
PORTVERSION=	1.2
CATEGORIES=	biology

MAINTAINER=	cartwright@asu.edu
COMMENT=	Tools for manipulating next-generation sequencing data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	htslib>=1.2:${PORTSDIR}/biology/htslib
LIB_DEPENDS=	libhts.so:${PORTSDIR}/biology/htslib

USE_GITHUB=	yes

USES=		gmake
SUB_FILES=	pkg-message

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV=	INSTALL_LIB="${INSTALL_LIB}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DIR="${MKDIR}"

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
