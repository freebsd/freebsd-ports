# New ports collection makefile for:	lzip
# Date created:		2009-06-20
# Whom:			Sylvio Cesar <sylvio@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lzip
PORTVERSION=	1.11
CATEGORIES=	archivers
MASTER_SITES=	SAVANNAH/lzip

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Is a lossless data compressor based on the LZMA algorithm

PLIST_FILES=	bin/lzip \
		bin/lziprecover

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS}" \
		LDFLAGS="${LDFLAGS}"
MAN1=		lzip.1 lziprecover.1
INFO=		lzip

.include <bsd.port.mk>
