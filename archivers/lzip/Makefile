# Created by: Sylvio Cesar <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lzip
PORTVERSION=	1.14
CATEGORIES=	archivers
MASTER_SITES=	SAVANNAH/lzip LOCAL/marino

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Lossless data compressor based on the LZMA algorithm

LICENSE=	GPLv3

PLIST_FILES=	bin/lzip

NO_STAGE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS}" \
		LDFLAGS="${LDFLAGS}"
MAN1=		lzip.1
INFO=		lzip

.include <bsd.port.mk>
